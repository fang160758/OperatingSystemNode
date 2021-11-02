/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:32:23
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 12:39:49
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
        // int ret = wait(NULL);
        int wstatus;
        int w;
        do
        {
            w = waitpid(ret, &wstatus, WUNTRACED | WCONTINUED);
            if (w == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(wstatus))
            {
                printf("exited, status=%d\n", WEXITSTATUS(wstatus));
            }
            else if (WIFSIGNALED(wstatus))
            {
                printf("killed by signal %d\n", WTERMSIG(wstatus));
            }
            else if (WIFSTOPPED(wstatus))
            {
                printf("stopped by signal %d\n", WSTOPSIG(wstatus));
            }
            else if (WIFCONTINUED(wstatus))
            {
                printf("continued\n");
            }
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        exit(EXIT_SUCCESS);
    }
    else
    {
        // int ret = wait(NULL);
        // std::cout << "Wait's on child ret = " << ret << std::endl;
        std::cout << "Child's pid = " << getpid() << std::endl;
        exit(1);
    }
}

/*
fang@fang:~/code/Operating Systream/Process-API$ ./out/q6
Child's pid = 47548
exited, status=1
*/