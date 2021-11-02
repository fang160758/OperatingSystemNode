/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-01 22:53:40
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 10:48:22
 */
/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-01 22:25:51
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 10:45:40
 */
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

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
        close(STDOUT_FILENO);
        open(".out//p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        char *margv[3];
        margv[0] = strdup("wc");
        margv[1] = strdup("p3.cc");
        margv[2] = NULL;
        execvp(margv[0], margv);
    }
    else
    {
        int t = wait(NULL);
        std::cout << "hello, I am parent of " << ret << " (wc = " << t << ") (pid = " << getpid() << ")\n";
    }
    return 0;
}
/*
fang@fang:~/code/Operating Systream/Process-API$ g++ p4.cc -o p4 -Wall
fang@fang:~/code/Operating Systream/Process-API$ ./p4
hello world (pid = 37419)
hello, I am parent of 37420 (wc = 37420) (pid = 37419)
fang@fang:~/code/Operating Systream/Process-API$ cat p4.output
  44  167 1064 p3.cc
fang@fang:~/code/Operating Systream/Process-API$
*/