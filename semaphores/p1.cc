/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-12 09:26:06
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-12 10:56:19
 */
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#define MAX 100
#define LOOP 100

int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get(void)
{
    int ret = buffer[use];
    use = (use + 1) % MAX;
    return ret;
}

sem_t mux;
sem_t esem;
sem_t fsem;

void *producer(void *argv)
{
    for (int i = 0; i < LOOP * 10; i++)
    {
        sem_wait(&esem);
        sem_wait(&mux);
        put(i);
        sem_post(&mux);
        sem_post(&fsem);
    }
    return NULL;
}

void *consumer(void *argv)
{
    char *str = (char *)argv;
    for (int i = 0; i < LOOP; i++)
    {
        sem_wait(&fsem);
        sem_wait(&mux);
        int res = get();
        std::cout << str << ": " << res << std::endl;
        sem_post(&mux);
        sem_post(&esem);
    }
    return NULL;
}

int main()
{
    sem_init(&mux, 0, 1);
    sem_init(&esem, 0, MAX);
    sem_init(&fsem, 0, 0);
    int N = 5;
    pthread_t pt[N];

    pthread_create(&pt[0], NULL, producer, NULL);
    for (int i = 1; i < N; i++)
    {
        pthread_create(&pt[i], NULL, consumer, (void *)"A");
    }
    for (int i = 1; i < N; i++)
    {
        pthread_join(pt[i], NULL);
    }

    return 0;
}
