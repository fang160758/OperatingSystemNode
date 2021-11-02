/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:32:23
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 12:33:15
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
        int ret = wait(NULL);
        std::cout << "Wait's on parent ret = " << ret << std::endl;
        std::cout << "Parent's pid = " << getpid() << std::endl;
        exit(1);
    }
    else
    {
        int ret = wait(NULL);
        std::cout << "Wait's on child ret = " << ret << std::endl;
        std::cout << "Child's pid = " << getpid() << std::endl;
        exit(1);
    }
}

/*
fang@fang:~/code/Operating Systream/Process-API$ ./out/q5
Wait's on child ret = -1
Child's pid = 46887
Wait's on parent ret = 46887
Parent's pid = 46886
*/