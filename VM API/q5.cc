/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-03 23:37:53
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-04 00:46:29
 */
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(sizeof(int) * 100);
    data[100] = 0;
}

/*
fang@fang:~/code/Operating Systream/VM API$ g++ q5.cc -o ./out/q5 -g
fang@fang:~/code/Operating Systream/VM API$ ./out/q5
fang@fang:~/code/Operating Systream/VM API$
*/

/*
(gdb) run
Starting program: /home/fang/code/Operating Systream/VM API/out/q5
[Inferior 1 (process 64369) exited normally]
*/

/*
fang@fang:~/code/Operating Systream/VM API$ valgrind --leak-check=yes ./out/q5
==90245== Memcheck, a memory error detector
==90245== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90245== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==90245== Command: ./out/q5
==90245==
==90245== Invalid write of size 4
==90245==    at 0x10866A: main (q5.cc:15)
==90245==  Address 0x522f1d0 is 0 bytes after a block of size 400 alloc'd
==90245==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==90245==    by 0x10865B: main (q5.cc:14)
==90245==
==90245==
==90245== HEAP SUMMARY:
==90245==     in use at exit: 400 bytes in 1 blocks
==90245==   total heap usage: 1 allocs, 0 frees, 400 bytes allocated
==90245==
==90245== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==90245==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==90245==    by 0x10865B: main (q5.cc:14)
==90245==
==90245== LEAK SUMMARY:
==90245==    definitely lost: 400 bytes in 1 blocks
==90245==    indirectly lost: 0 bytes in 0 blocks
==90245==      possibly lost: 0 bytes in 0 blocks
==90245==    still reachable: 0 bytes in 0 blocks
==90245==         suppressed: 0 bytes in 0 blocks
==90245==
==90245== For counts of detected and suppressed errors, rerun with: -v
==90245== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
*/