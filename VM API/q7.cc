/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-03 23:37:53
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-03 23:48:32
 */
#include <stdlib.h>

int main()
{
    int *data = (int *)malloc(sizeof(int) * 100);
    free(data + 10);
}
/*
fang@fang:~/code/Operating Systream/VM API$ g++ q7.cc -o ./out/q7 -g
fang@fang:~/code/Operating Systream/VM API$ ./out/q7
free(): invalid pointer
Aborted (core dumped)
*/
//不需要工具来查找这类释放内存的错误