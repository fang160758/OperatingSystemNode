/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-03 22:59:45
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-04 00:51:03
 */
#include <stdlib.h>

int main()
{
    int *ptr = NULL;
    free(ptr);

    // int *ptr = (int *)malloc(sizeof(int) * 10);
    // free(ptr);
    return 0;
}

// 1.首先,编写一个名为 null.c 的简单程序,它创建一个指向整数的指针,将其设置为 NULL,然后尝试对其进行释放内存操作。把它编译成一个名为 null 的可执行文件。当你运行这个程序时会发生什么?
//什么都没有发生
/*
fang@fang:~/code/Operating Systream/VM API$ ./out/null
fang@fang:~/code/Operating Systream/VM API$
*/

/*
2．接下来，编译该程序，其中包含符号信息（使用-g 标志）。这样做可以将本多信息
放入可执行文件中，使调试器可以但问有关变量名称等的本多有用信息。通过输入 gdb null，
在调试器下运行该程序，然后，一旦 gdb 运行，输入 run。gdb 显示什么信息？

(gdb) run
Starting program : /
home / fang / code / Operating Systream / VM API / out / null[Inferior 1(process 63103)exited normally]
*/

/*
==89776== Memcheck, a memory error detector
==89776== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==89776== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==89776== Command: ./out/null
==89776==
==89776==
==89776== HEAP SUMMARY:
==89776==     in use at exit: 0 bytes in 0 blocks
==89776==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==89776==
==89776== All heap blocks were freed -- no leaks are possible
==89776==
==89776== For counts of detected and suppressed errors, rerun with: -v
==89776== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/