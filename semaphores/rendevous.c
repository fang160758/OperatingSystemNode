/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-12 11:03:08
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-12 11:09:49
 */
#include <stdio.h>
#include <unistd.h>
#include "common_threads.h"

// If done correctly, each child should print their "before" message
// before either prints their "after" message. Test by adding sleep(1)
// calls in various locations.

sem_t s1, s2;

void *child_1(void *arg)
{
    printf("child 1: before\n");
    // what goes here?
    sem_post(&s2);
    sem_wait(&s1);
    printf("child 1: after\n");
    return NULL;
}

void *child_2(void *arg)
{
    printf("child 2: before\n");
    // what goes here?
    sem_post(&s1);
    sem_wait(&s2);
    printf("child 2: after\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2;
    printf("parent: begin\n");
    // init semaphores here
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    Pthread_create(&p1, NULL, child_1, NULL);
    Pthread_create(&p2, NULL, child_2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("parent: end\n");
    return 0;
}
/*
fang@fang:~/code/Operating Systream/semaphores$ gcc rendevous.c -o ./out/rendevous -lpthread
fang@fang:~/code/Operating Systream/semaphores$ ./out/rendevous
parent: begin
child 1: before
child 2: before
child 1: after
child 2: after
parent: end
*/