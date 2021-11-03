/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-04 00:11:09
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-04 00:48:13
 */
#include <stdlib.h>
#include <iostream>

#define DEFAULT_SIZE 10

typedef struct Vector
{
    float *x;
    float *y;
    int len;
    int max_len;
} Vector;

void v_append(Vector *, float, float);
void v_free(Vector *);

int main()
{
    Vector v = {
        .x = (float *)malloc(sizeof(float) * DEFAULT_SIZE),
        .y = (float *)malloc(sizeof(float) * DEFAULT_SIZE),
        .len = 0,
        .max_len = DEFAULT_SIZE};
    for (int j = 0; j < 20; j++)
        v_append(&v, j, j * 0.34);
    v_append(&v, 2, 3);
    for (int i = 0; i < v.len; i++)
        std::cout << "(" << v.x[i] << ", " << v.y[i] << ")" << std::endl;
    v_free(&v);
    return 0;
}

void v_append(Vector *vet, float x, float y)
{
    if ((*vet).len + 1 >= (*vet).max_len)
    {
        (*vet).max_len += DEFAULT_SIZE;
        (*vet).x = (float *)realloc((*vet).x, sizeof(float) * (*vet).max_len);
        (*vet).y = (float *)realloc((*vet).y, sizeof(float) * (*vet).max_len);
    }
    (*vet).x[(*vet).len] = x;
    (*vet).y[(*vet).len] = y;
    (*vet).len++;
}

void v_free(Vector *vet)
{
    free((*vet).x);
    free((*vet).y);
}

/*
fang@fang:~/code/Operating Systream/VM API$ g++ q8.cc -o ./out/q8 -g
fang@fang:~/code/Operating Systream/VM API$ ./out/q8
(0, 0)
(1, 0.34)
(2, 0.68)
(3, 1.02)
(4, 1.36)
(5, 1.7)
(6, 2.04)
(7, 2.38)
(8, 2.72)
(9, 3.06)
(10, 3.4)
(11, 3.74)
(12, 4.08)
(13, 4.42)
(14, 4.76)
(15, 5.1)
(16, 5.44)
(17, 5.78)
(18, 6.12)
(19, 6.46)
(2, 3)
*/

/*
(gdb) run
Starting program: /home/fang/code/Operating Systream/VM API/out/q8
(0, 0)
(1, 0.34)
(2, 0.68)
(3, 1.02)
(4, 1.36)
(5, 1.7)
(6, 2.04)
(7, 2.38)
(8, 2.72)
(9, 3.06)
(10, 3.4)
(11, 3.74)
(12, 4.08)
(13, 4.42)
(14, 4.76)
(15, 5.1)
(16, 5.44)
(17, 5.78)
(18, 6.12)
(19, 6.46)
(2, 3)
[Inferior 1 (process 88692) exited normally]
*/

/*
fang@fang:~/code/Operating Systream/VM API$ valgrind --leak-check=yes ./out/q8
==90376== Memcheck, a memory error detector
==90376== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90376== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==90376== Command: ./out/q8
==90376==
(0, 0)
(1, 0.34)
(2, 0.68)
(3, 1.02)
(4, 1.36)
(5, 1.7)
(6, 2.04)
(7, 2.38)
(8, 2.72)
(9, 3.06)
(10, 3.4)
(11, 3.74)
(12, 4.08)
(13, 4.42)
(14, 4.76)
(15, 5.1)
(16, 5.44)
(17, 5.78)
(18, 6.12)
(19, 6.46)
(2, 3)
==90376==
==90376== HEAP SUMMARY:
==90376==     in use at exit: 0 bytes in 0 blocks
==90376==   total heap usage: 8 allocs, 8 frees, 74,208 bytes allocated
==90376==
==90376== All heap blocks were freed -- no leaks are possible
==90376==
==90376== For counts of detected and suppressed errors, rerun with: -v
==90376== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/