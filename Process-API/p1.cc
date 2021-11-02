/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-01 22:25:51
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-01 22:31:52
 */
#include <unistd.h>
#include <iostream>

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
        std::cout << "hello, I am child (pid = " << getpid() << ")\n";
    else
        std::cout << "hello, I am parent of " << ret << " (pid = " << getpid() << ")\n";
    return 0;
}
/*
hello world (pid = 36448)
hello, I am parent of 36449 (pid = 36448)
hello, I am child (pid = 36449)
*/