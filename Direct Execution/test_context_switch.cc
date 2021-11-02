/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 14:56:25
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 15:16:01
 */
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <assert.h>
int main(int argc, char *argv[])
{
    assert(argc > 1);
    int loop = atoi(argv[1]);
    cpu_set_t set;
    timeval t_b, t_e;
    int pd1[2], pd2[2], pd[2];
    CPU_SET(0, &set);

    if (pipe(pd1) == -1 || pipe(pd2) == -1 || pipe(pd) == -1)
    {
        std::cout << "pipe failed!" << std::endl;
        return 0;
    }
    switch (fork())
    {
    case -1:
        std::cout << "fork failed!" << std::endl;
        break;
    case 0:
        if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
            std::cout << "sched failed!" << std::endl;
        else
        {
            gettimeofday(&t_b, NULL);
            for (int i = 0; i < loop; i++)
            {
                read(pd1[0], NULL, 1);
                write(pd2[1], "h", 1);
            }
            write(pd[1], &t_b, sizeof(t_b));
        }
        break;
    default:
        if (sched_setaffinity(getpid(), sizeof(set), &set) == -1)
            std::cout << "sched failed!" << std::endl;
        else
        {
            for (int i = 0; i < loop; i++)
            {
                write(pd1[1], "h", 1);
                read(pd2[0], NULL, 1);
            }
            read(pd[0], &t_b, sizeof(t_b));
            gettimeofday(&t_e, NULL);
            std::cout << "context switch time of: "
                      << (float)(t_e.tv_sec * 1000000 + t_e.tv_usec - t_b.tv_sec * 1000000 - t_b.tv_usec) / loop / 2
                      << std::endl;
        }
    }
}
/*
fang@fang:~/code/Operating Systream/Direct Execution$ ./out/test_context_switch 50000
context switch time of: 1.87698
*/