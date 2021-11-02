/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 14:30:40
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 14:40:23
 */
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage numbern" << std::endl;
        return 0;
    }
    int n = atoi(argv[1]);
    struct timeval tm1, tm2;
    gettimeofday(&tm1, 0);
    for (int i = 0; i < n; i++)
        read(0, 0, 0);
    gettimeofday(&tm2, 0);
    std::cout << "execl time of: " << (float)(tm2.tv_sec * 1000000 + tm2.tv_usec - tm1.tv_sec * 1000000 - tm1.tv_usec) / n << std::endl;
}