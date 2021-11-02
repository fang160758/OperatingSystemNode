/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-02 10:32:23
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-02 10:43:26
 */
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
int main()
{
    // int x = 0;
    int *p = new int(0);
    int ret = fork();
    if (ret < 0)
    {
        std::cout << "fork failed!";
        exit(1);
    }
    else if (ret > 0)
    {
        // std::cout << "The old value of 'x' on parent process: " << x << std::endl;
        // x = 100;
        // std::cout << "The new value of 'x' on parent process: " << x << std::endl;

        std::cout << "The old value of '*p' on parent process: " << *p << std::endl;
        *p = 100;
        std::cout << "The new value of '*p' on parent process: " << *p << std::endl;
    }
    else
    {
        // std::cout << "The old value of 'x' on chrild process: " << x << std::endl;
        // x = 200;
        // std::cout << "The new value of 'x' on chrild process: " << x << std::endl;
        std::cout << "The old value of '*p' on chrild process: " << *p << std::endl;
        *p = 200;
        std::cout << "The new value of '*p' on chrild process: " << *p << std::endl;
    }
}
/*
The old value of 'x' on parent process: 0
The new value of 'x' on parent process: 100
The old value of 'x' on chrild process: 0
The new value of 'x' on chrild process: 200
*/

/*
The old value of '*p' on parent process: 0
The new value of '*p' on parent process: 100
The old value of '*p' on chrild process: 0
The new value of '*p' on chrild process: 200
*/