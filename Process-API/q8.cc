/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 12:50:15
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 12:57:46
 */
#include <unistd.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    assert(pipe(pipefd) != -1);

    int cpid = fork();
    if (cpid == 0)
    {
        int ccpid = fork();
        if (ccpid == 0)
        {
            const char *msg = "Hello\n";
            close(pipefd[0]);
            write(pipefd[1], msg, sizeof(msg) * strlen(msg));
        }
        else if (ccpid > 0)
        {
            wait(NULL);
            char asw[10];
            close(pipefd[1]);
            read(pipefd[0], asw, sizeof(char) * 10);
            std::cout << asw << std::endl;
        }
    }
    return 0;
}