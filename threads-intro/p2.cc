/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-07 20:11:10
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-07 20:25:47
 */
#include <pthread.h>
#include <iostream>
#include <assert.h>

static volatile int count = 0;

// static void *mythread(void *arg)
// {
//     std::cout << (char *)arg << std::endl;
// }

static void *mythread(void *arg)
{
    std::cout << (char *)arg << " begin" << std::endl;
    for (int i = 0; i < 1e7; i++)
        count++;
    std::cout << (char *)arg << " end" << std::endl;
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

    std::cout << "the count = " << count << std::endl;
    std::cout << "main end" << std::endl;
    return 0;
}
//预计结果 count == 20000000
/*
实际结果：
fang@fang:~/code/Operating Systream/并发$ ./out/p2
main begin
A begin
B begin
A end
B end
the count = 16377575
main end
fang@fang:~/code/Operating Systream/并发$ ./out/p2
main begin
A begin
B begin
B end
A end
the count = 12220141
main end

且每次运行都不一样
*/