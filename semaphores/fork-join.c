/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-12 10:58:56
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-12 11:05:28
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "common_threads.h"

sem_t s;

void *child(void *arg)
{
    printf("child\n");
    // use semaphore here
    sem_post(&s);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p;
    printf("parent: begin\n");
    // init semaphore here
    sem_init(&s, 0, 0);
    Pthread_create(&p, NULL, child, NULL);
    sem_wait(&s);
    // use semaphore here
    // sleep(1);
    printf("parent: end\n");
    return 0;
}
/*
fang@fang:~/code/Operating Systream/semaphores$ ./out/fork-join
parent: begin
child
parent: end
*/