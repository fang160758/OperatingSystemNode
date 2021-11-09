/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-07 20:11:10
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-07 20:20:47
 */
#include <pthread.h>
#include <iostream>
#include <assert.h>

static void *mythread(void *arg)
{
    std::cout << (char *)arg << std::endl;
}

int main()
{
    pthread_t p1, p2;
    int rc;
    std::cout << "main begin" << std::endl;
    rc = pthread_create(&p1, NULL, mythread, (void *)"A");
    assert(rc == 0);
    rc = pthread_create(&p2, NULL, mythread, (void *)"B");
    assert(rc == 0);

    rc = pthread_join(p1, NULL);
    assert(rc == 0);
    rc = pthread_join(p2, NULL);
    assert(rc == 0);
    std::cout << "main end" << std::endl;
    return 0;
}

/*
fang@fang:~/code/Operating Systream/并发$ ./out/p1
main begin
A
B
main end
*/