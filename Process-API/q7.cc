/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:32:23
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 12:50:08
 */
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main()
{
    int ret = fork();
    if (ret < 0)
    {
        std::cout << "fork failed!";
        exit(1);
    }
    else if (ret > 0)
    {
        // wait(NULL);  yes
        // int ret = open("./out/q1.cc", 0, 0); error
        std::cout << "parent sleep(1)!" << std::endl;
        sleep(1);
        std::cout << "goodbye" << std::endl;
        exit(1);
    }
    else
    {
        close(STDOUT_FILENO);
        printf("Hello");
        // std::cout << "hello" << std::endl;

        // exit(1);
    }
}

/*
fang@fang:~/code/Operating Systream/Process-API$ ./out/q7
parent sleep(1)!
goodbye
*/