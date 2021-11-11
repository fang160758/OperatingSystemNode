/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-10 22:33:57
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-11 11:02:22
 */
#include "time.h"
#include <iostream>
#include <pthread.h>

#define NUMCPUS 4
typedef struct
{
    int global;           //全局计数器
    pthread_mutex_t gmux; //全局锁

    int local[NUMCPUS];            //局部计数器
    pthread_mutex_t lmux[NUMCPUS]; //局部锁
    int S;                         //阀值，局部计数器超过阀值就加入到全局计数器中，局部计数器清零
} Node;

void init_node(Node *node, int s)
{
    node->global = 0;
    node->S = s;
    pthread_mutex_init(&node->gmux, nullptr);
    for (int i = 0; i < NUMCPUS; i++)
    {
        pthread_mutex_init(&node->lmux[i], nullptr);
        node->local[i] = 0;
    }
}

void increment(Node *node, int index, int num)
{
    pthread_mutex_lock(&node->lmux[index]);
    node->local[index] += num;
    if (node->local[index] >= node->S)
    {
        pthread_mutex_lock(&node->gmux);
        node->global += node->local[index];
        pthread_mutex_unlock(&node->gmux);
        node->local[index] = 0;
    }
    pthread_mutex_unlock(&node->lmux[index]);
}

int get(Node *node)
{
    pthread_mutex_lock(&node->gmux);
    int ret = node->global;
    pthread_mutex_unlock(&node->gmux);
    return ret;
}

typedef struct
{
    Node node;
    int index;
    int num;
} Args;

static void *
worker(void *arg)
{
    Args *args = (Args *)arg;
    for (int i = 0; i < 10000; i++)
        increment(&args->node, args->index, args->num);
    return NULL;
}
int main()
{
    double start, end;
    int loop = 10;
    pthread_t pt[NUMCPUS];
    Node node;
    int s[loop] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    Args arg;
    for (int t = 0; t < loop; t++)
    {
        init_node(&node, s[t]);

        start = Time_Get();
        arg.node = node;
        arg.num = 1;
        for (int i = 0; i < NUMCPUS; i++)
        {
            arg.index = i;
            pthread_create(&pt[i], nullptr, worker, &arg);
        }
        for (int i = 0; i < NUMCPUS; i++)
            pthread_join(pt[i], nullptr);
        end = Time_Get();
        std::cout << end - start << std::endl;
    }
}

/*
fang@fang:~/code/Operating Systream/Lock Usage$ g++ q3.cc -o ./out/q3 -g -lpthread
fang@fang:~/code/Operating Systream/Lock Usage$ ./out/q3
0.010983
0.00710988
0.00273299
0.00308204
0.00178909
0.00212002
0.00261712
0.00310397
0.00294399
0.00482702
*/