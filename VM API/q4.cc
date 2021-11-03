/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-03 23:37:53
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-04 00:44:54
 */
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    return 0;
}
/*
fang@fang:~/code/Operating Systream/VM API$ g++ q4.cc -o ./out/q4 -g
fang@fang:~/code/Operating Systream/VM API$ ./out/q4
fang@fang:~/code/Operating Systream/VM API$
*/

/*
(gdb) r
Starting program: /home/fang/code/Operating Systream/VM API/out/q4
[Inferior 1 (process 63996) exited normally]
*/

/*
fang@fang:~/code/Operating Systream/VM API$ valgrind --leak-check=yes ./out/q4
==90108== Memcheck, a memory error detector
==90108== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90108== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==90108== Command: ./out/q4
==90108==
==90108==
==90108== HEAP SUMMARY:
==90108==     in use at exit: 4 bytes in 1 blocks
==90108==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==90108==
==90108== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==90108==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==90108==    by 0x10865B: main (q4.cc:14)
==90108==
==90108== LEAK SUMMARY:
==90108==    definitely lost: 4 bytes in 1 blocks
==90108==    indirectly lost: 0 bytes in 0 blocks
==90108==      possibly lost: 0 bytes in 0 blocks
==90108==    still reachable: 0 bytes in 0 blocks
==90108==         suppressed: 0 bytes in 0 blocks
==90108==
==90108== For counts of detected and suppressed errors, rerun with: -v
==90108== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/