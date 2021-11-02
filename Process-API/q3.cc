/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:32:23
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 11:56:17
 */
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
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
        std::cout << "hello" << std::endl;
        exit(1);
    }
}

/*
fang@fang:~/code/Operating Systream/Process-API$ ./out/q3
parent sleep(1)!
hello
goodbye
*/