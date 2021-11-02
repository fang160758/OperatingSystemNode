/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-01 22:25:51
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-01 22:44:50
 */
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <string.h>
int main()
{
    std::cout << "hello world (pid = " << getpid() << ")\n";
    int ret = fork();
    if (ret < 0)
    {
        std::cout << "fork failed\n";
        exit(1);
    }
    else if (ret == 0)
    {
        std::cout << "hello, I am child (pid = " << getpid() << ")\n";
        char *margv[3];
        margv[0] = strdup("wc");
        margv[1] = strdup("p3.cc");
        margv[2] = NULL;
        execvp(margv[0], margv);
        std::cout << "this shouldn't print out" << std::endl;
    }
    else
    {
        int t = wait(NULL);
        std::cout << "hello, I am parent of " << ret << " (wc = " << t << ") (pid = " << getpid() << ")\n";
    }
    return 0;
}
/*
hello world (pid = 36970)
hello, I am child (pid = 36971)
 39 137 928 p3.cc
hello, I am parent of 36971 (wc = 36971) (pid = 36970)
*/