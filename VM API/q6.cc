/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-03 23:37:53
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-04 00:47:40
 */
#include <stdlib.h>
#include <iostream>
int main()
{
    int *data = (int *)malloc(sizeof(int) * 100);
    free(data);
    std::cout << data[10] << std::endl;
    return 0;
}
/*
fang@fang:~/code/Operating Systream/VM API$ g++ q6.cc -o ./out/q6 -g
fang@fang:~/code/Operating Systream/VM API$ ./out/q6
0
*/

/*
fang@fang:~/code/Operating Systream/VM API$ valgrind --leak-check=yes ./out/q6
==90317== Memcheck, a memory error detector
==90317== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90317== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==90317== Command: ./out/q6
==90317==
==90317== Invalid read of size 4
==90317==    at 0x108944: main (q6.cc:16)
==90317==  Address 0x5b7fca8 is 40 bytes inside a block of size 400 free'd
==90317==    at 0x4C32D3B: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==90317==    by 0x10893B: main (q6.cc:15)
==90317==  Block was alloc'd at
==90317==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==90317==    by 0x10892B: main (q6.cc:14)
==90317==
0
==90317==
==90317== HEAP SUMMARY:
==90317==     in use at exit: 0 bytes in 0 blocks
==90317==   total heap usage: 3 allocs, 3 frees, 74,128 bytes allocated
==90317==
==90317== All heap blocks were freed -- no leaks are possible
==90317==
==90317== For counts of detected and suppressed errors, rerun with: -v
==90317== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/