/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-11 21:01:40
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-11 21:24:19
 */
#include <pthread.h>
#include <iostream>

#define MAX 100
#define LOOP 100

int buffer[MAX];
int fill = 0;
int use = 0;
int count = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
    count++;
}

int get(void)
{
    int ret = buffer[use];
    use = (use + 1) % MAX;
    count--;
    return ret;
}

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t fcond = PTHREAD_COND_INITIALIZER;
pthread_cond_t econd = PTHREAD_COND_INITIALIZER;

static void *producer(void *argv)
{

    for (int i = 0; i < LOOP; i++)
    {
        pthread_mutex_lock(&mux);
        while (count == MAX)
        {
            pthread_cond_wait(&econd, &mux);
        }
        put(i);
        pthread_cond_signal(&fcond);
        pthread_mutex_unlock(&mux);
    }
}

static void *consumer(void *argv)
{

    char *str = (char *)argv;
    for (int i = 0; i < LOOP; i++)
    {
        pthread_mutex_lock(&mux);
        while (count == 0)
        {
            pthread_cond_wait(&fcond, &mux);
        }
        std::cout << str << ": " << get() << std::endl;
        pthread_cond_signal(&econd);
        pthread_mutex_unlock(&mux);
    }
}

int main()
{
    std::cout << "The parent running!" << std::endl;
    pthread_t pt[4];
    pthread_create(&pt[0], NULL, producer, NULL);
    pthread_create(&pt[3], NULL, producer, NULL);
    pthread_create(&pt[1], NULL, consumer, (void *)"A");
    pthread_create(&pt[2], NULL, consumer, (void *)"B");
    pthread_join(pt[1], NULL);
    pthread_join(pt[2], NULL);
    return 0;
}