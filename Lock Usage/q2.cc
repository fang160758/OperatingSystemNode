/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-10 22:33:57
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-10 22:48:56
 */
#include "time.h"
#include <iostream>
#include <pthread.h>

typedef struct
{
    int value;
    pthread_mutex_t mux;
} Node;

void init_node(Node *node)
{
    node->value = 0;
    pthread_mutex_init(&node->mux, nullptr);
}

void increment(Node *node)
{
    pthread_mutex_lock(&node->mux);
    node->value++;
    pthread_mutex_unlock(&node->mux);
}

void decrement(Node *node)
{
    pthread_mutex_lock(&node->mux);
    node->value--;
    pthread_mutex_unlock(&node->mux);
}

int get(Node *node)
{
    pthread_mutex_lock(&node->mux);
    int ret = node->value;
    pthread_mutex_unlock(&node->mux);
    return ret;
}

static void *worker(void *arg)
{
    Node *node = (Node *)arg;
    for (int i = 0; i < 1e6; i++)
        increment(node);
    return NULL;
}
int main()
{
    double start, end;
    int loop = 5;
    pthread_t pt[loop];
    Node node;
    for (int t = 0; t < loop; t++)
    {
        init_node(&node);
        start = Time_Get();
        for (int i = 0; i < loop; i++)
            pthread_create(&pt[i], nullptr, worker, &node);
        for (int i = 0; i < loop; i++)
            pthread_join(pt[i], nullptr);
        end = Time_Get();
        std::cout << end - start << std::endl;
    }
}

/*
fang@fang:~/code/Operating Systream/Lock Usage$ g++ q2.cc -o ./out/q2 -g -lpthread
fang@fang:~/code/Operating Systream/Lock Usage$ ./out/q2
0.222676
0.247114
0.267917
0.260511
0.233036
*/