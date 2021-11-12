/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-12 20:18:32
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-12 21:24:55
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

    sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    int acceptfd = accept(listenfd, (struct sockaddr *)&client_addr, &addrlen);
    assert(acceptfd != -1);
    time_t t;
    char buf[64];
    tm ptm;
    char message[64];
    while (1)
    {
        time(&t);
        localtime_r(&t, &ptm);
        strftime(buf, sizeof(buf) - 1, "%Y-%m-%d %H:%M:%S", &ptm);

        write(acceptfd, buf, sizeof(buf));
        read(acceptfd, message, sizeof(message));
        std::cout << message << std::endl;
        sleep(1);
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
    const char *message = "The chilent!";
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