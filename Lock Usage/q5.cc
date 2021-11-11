#include <iostream>
#include <assert.h>
#include <pthread.h>
#include "time.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    pthread_mutex_t hmux;
    pthread_mutex_t tmux;

} Queue;

void Queue_init(Queue *queue)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = nullptr;
    queue->head = queue->tail = node;
    pthread_mutex_init(&queue->hmux, nullptr);
    pthread_mutex_init(&queue->tmux, nullptr);
}

void enqueue(Queue *queue, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    assert(node != nullptr);
    node->value = value;
    node->next = nullptr;
    pthread_mutex_lock(&queue->tmux);
    queue->tail->next = node;
    queue->tail = node;
    pthread_mutex_unlock(&queue->tmux);
}

int dequeue(Queue *queue, int &value)
{
    pthread_mutex_lock(&queue->hmux);
    Node *node = queue->head->next;
    if (!node)
    {
        pthread_mutex_unlock(&queue->hmux);
        return 0;
    }
    value = node->value;
    free(queue->head);
    queue->head = node;
    pthread_mutex_unlock(&queue->hmux);
    return 1;
}

void freequeue(Queue *queue)
{
    int ret;
    while (dequeue(queue, ret))
        ;
}

static void *worker(void *arg)
{
    Queue *queue = (Queue *)arg;
    for (int i = 0; i < 10000; i++)
    {
        if (i % 2 == 0)
            enqueue(queue, i);
        else
            dequeue(queue, i);
    }
    return NULL;
}

#define MAX_WORKER 8
int main()
{
    double start, end;
    pthread_t pt[MAX_WORKER];
    Queue queue;
    for (int t = 1; t <= MAX_WORKER; t++)
    {
        Queue_init(&queue);
        start = Time_Get();
        for (int i = 0; i < t; i++)
            pthread_create(&pt[i], nullptr, worker, &queue);
        for (int i = 0; i < t; i++)
            pthread_join(pt[i], nullptr);
        end = Time_Get();
        std::cout << end - start << std::endl;
        freequeue(&queue);
    }
}

/*
fang@fang:~/code/Operating Systream/Lock Usage$ ./out/q5
0.00047493
0.00191402
0.00478601
0.00276303
0.00543308
0.00307083
0.00971889
0.00883579
*/