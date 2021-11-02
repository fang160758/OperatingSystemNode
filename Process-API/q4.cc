/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 11:57:48
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 12:26:20
 */
#include <unistd.h>
#include <iostream>
#include <string.h>
int main()
{
    int ret = fork();
    if (ret > 0)
    {
        std::cout << " This is parent process!" << std::endl;
        char *margv[3];
        margv[0] = strdup("ls");
        margv[1] = strdup("-al");
        margv[2] = NULL;
        execvp(margv[0], margv);
        std::cout << std::endl;
        execv(margv[0], margv);
    }
    else if (ret == 0)
    {
        char *margv[5] = {"/bin/ls", "ls", "-al", nullptr};
        execl(margv[0], margv[1], margv[2], margv[3]);
    }
    else
    {
        std::cout << "fork failed!" << std::endl;
    }
}