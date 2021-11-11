/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-11 20:10:35
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-11 20:28:03
 */
#include <pthread.h>
#include <iostream>
#include <unistd.h>

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int done = 0;

// void thr_join()
// {
//     pthread_mutex_lock(&mux);
//     while (done == 0)
//     {
//         pthread_cond_wait(&cond, &mux);
//     }
//     pthread_mutex_unlock(&mux);
// }

// void thr_exl()
// {
//     pthread_mutex_lock(&mux);
//     done = 1;
//     pthread_cond_signal(&cond);
//     pthread_mutex_unlock(&mux);
// }

void thr_join()
{
    pthread_mutex_lock(&mux);
    // while (done == 0)
    // {
    pthread_cond_wait(&cond, &mux);
    // }
    pthread_mutex_unlock(&mux);
}

void thr_exl()
{
    pthread_mutex_lock(&mux);
    // done = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mux);
}

static void *worker(void *argv)
{
    std::cout << "The childer running!" << std::endl;
    thr_exl();
    return NULL;
}

int main()
{
    pthread_t pt;
    std::cout << "The parent running!" << std::endl;
    pthread_create(&pt, NULL, worker, NULL);
    sleep(2); //为了让子线程先运行然后主线程在调用join函数进入wait此时没有线程去唤醒主线程就会卡死。
    thr_join();
    std::cout << "The parent end!" << std::endl;
    return 0;
}