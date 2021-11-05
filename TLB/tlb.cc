/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-05 20:42:22
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-05 21:04:06
 */
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#define PAGESIZE 4096
int main(int argc, char *argv[])
{
    assert(argc == 5);
    int opt;
    int loop, pages;
    while ((opt = getopt(argc, argv, "l:p:")) != -1)
    {
        switch (opt)
        {
        case 'l':
            loop = atoi(optarg);
            break;
        case 'p':
            pages = atoi(optarg);
            break;
        }
    }
    int jump = PAGESIZE / sizeof(int);
    int *arr = (int *)malloc(sizeof(int) * jump * pages);
    timeval tb, te;
    gettimeofday(&tb, NULL);
    for (int j = 0; j < loop; j++)
        for (int i = 0; i < pages * jump; i += jump)
            arr[i] += 1;
    gettimeofday(&te, NULL);
    std::cout << (float)(te.tv_sec * 1000000 + te.tv_usec - tb.tv_sec * 1000000 - tb.tv_usec) / (loop * pages) << std::endl;
}