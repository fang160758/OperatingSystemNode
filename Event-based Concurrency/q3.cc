/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-12 20:18:32
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-12 22:01:14
 */
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void *server(void *argv)
{
    sockaddr_in server_addr;
    server_addr.sin_port = htons(8080);
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    int ret = bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    assert(ret != -1);

    ret = listen(listenfd, 5);
    assert(ret != -1);

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(listenfd, &read_fds);

    time_t t;
    char buf[64];
    tm ptm;
    char message[64];
    while (1)
    {
        assert(select(FD_SETSIZE, &read_fds, 0, 0, 0) >= 0);
        for (int i = 0; i < FD_SETSIZE; i++)
        {
            if (FD_ISSET(i, &read_fds))
            {
                if (i == listenfd)
                {
                    sockaddr_in client_addr;
                    socklen_t addrlen = sizeof(client_addr);
                    int acceptfd = accept(listenfd, (struct sockaddr *)&client_addr, &addrlen);
                    assert(acceptfd != -1);
                    FD_SET(acceptfd, &read_fds);
                    std::cout << "connect!" << std::endl;
                }
                else
                {
                    char *filename = (char *)malloc(sizeof(char) * 64);
                    assert(read(i, filename, 64) > 0);
                    int fd = open(filename, O_CREAT | O_WRONLY);
                    assert(fd != 0);
                    read(fd, filename, 64);
                    write(i, filename, 64);
                    free(filename);
                    FD_CLR(i, &read_fds);
                }
            }
        }
    }
    return NULL;
}

void *client(void *argv)
{
    sleep(1);
    sockaddr_in server_addr;
    server_addr.sin_port = htons(8080);
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    int ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    assert(ret != -1);
    const char *message = "1.txt";
    char buf[64];
    while (1)
    {
        write(sock, message, strlen(message));
        read(sock, buf, sizeof(buf) - 1);
        std::cout << buf << std::endl;
        // sleep(1);
    }
}
int main()
{
    pthread_t ps, pc;
    pthread_create(&ps, NULL, server, NULL);
    pthread_create(&pc, NULL, client, NULL);
    pthread_join(ps, NULL);
    pthread_join(pc, NULL);
    return 0;
}