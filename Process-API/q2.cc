/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:43:37
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 11:47:37
 */
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd = open("./out/read.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    write(fd, "abcdef\n", 7);
    int ret = fork();
    if (ret < 0)
    {
        std::cout << "fork failed!" << std::endl;
        exit(1);
    }
    else if (ret > 0)
    {
        char buf[10];
        bzero(buf, strlen(buf));
        int ret = read(fd, buf, sizeof(buf) - 1);
        std::cout << "the value of read on parent process: " << std::string(buf) << std::endl;
        const char *wr = "parent's write\n";
        write(fd, wr, strlen(wr));
    }
    else
    {
        char buf[10];
        bzero(buf, strlen(buf));
        int ret = read(fd, buf, sizeof(buf) - 1);
        std::cout << "the value of read on chrild process: " << std::string(buf) << std::endl;
        const char *wr = "chrild's write\n";
        write(fd, wr, strlen(wr));
    }
}

/*
fang@fang:~/code/Operating Systream/Process-API$ ./out/q2
the value of read on parent process:
the value of read on chrild process:
*/

/*
abcdef
parent's write
chrild's write
*/