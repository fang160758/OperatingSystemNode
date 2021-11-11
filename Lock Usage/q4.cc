#include <iostream>
#include <assert.h>
#include <pthread.h>
#include "time.h"

typedef struct Node
{
    int key;
    struct Node *next;
    pthread_mutex_t mux;
} Node;

typedef struct
{
    Node *head;
    pthread_mutex_t mux;
} List;

void List_init(List *list)
{
    list->head = nullptr;
    pthread_mutex_init(&list->mux, nullptr);
}

int List_insert(List *list, int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == nullptr)
    {
        std::cout << "Node malloc error!" << std::endl;
        return 0;
    }
    pthread_mutex_init(&node->mux, nullptr);
    node->key = key;
    pthread_mutex_lock(&list->mux);
    node->next = list->head;
    list->head = node;
    pthread_mutex_unlock(&list->mux);
    return 1;
}

int lookup(List *list, int key)
{
    pthread_mutex_lock(&list->mux);
    Node *node = list->head;
    pthread_mutex_lock(&node->mux);
    pthread_mutex_unlock(&list->mux);
    int flag = 0;
    while (node)
    {
        if (node->key == key)
        {
            flag = 1;
            break;
        }
        pthread_mutex_lock(&node->next->mux);
        pthread_mutex_unlock(&node->mux);
        node = node->next;
    }
    pthread_mutex_unlock(&node->mux);
    return flag;
}

void List_free(List *list)
{
    pthread_mutex_lock(&list->mux);
    Node *node = list->head;
    Node *next = nullptr;
    while (node)
    {
        next = node->next;
        free(node);
        node = next;
    }
    pthread_mutex_unlock(&list->mux);
}

static void *worker(void *arg)
{
    List *list = (List *)arg;
    for (int i = 0; i < 10000; i++)
    {
        List_insert(list, i);
        int status = lookup(list, i);
    }
    return NULL;
}

#define MAX_WORKER 8
int main()
{
    double start, end;
    pthread_t pt[MAX_WORKER];
    List list;
    for (int t = 1; t <= MAX_WORKER; t++)
    {
        List_init(&list);
        start = Time_Get();
        for (int i = 0; i < t; i++)
            pthread_create(&pt[i], nullptr, worker, &list);
        for (int i = 0; i < t; i++)
            pthread_join(pt[i], nullptr);
        end = Time_Get();
        std::cout << end - start << std::endl;
        List_free(&list);
    }
}

/*
fang@fang:~/code/Operating Systream/Lock Usage$ g++ q4.cc -o ./out/q4 -g -lpthread
fang@fang:~/code/Operating Systream/Lock Usage$ ./out/q4
0.00115108
0.00280094
0.0101471
0.00480008
0.013123
0.018065
0.0128379
0.0121441
*/