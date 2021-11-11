/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-11 19:41:13
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-11 21:41:42
 */
/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-11 19:41:13
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-11 19:53:41
 */
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
static void *Childer(void *argv)
{
    int fp = open("re.txt", O_CREAT | O_WRONLY);
    const char *str = "The childer running!";
    write(fp, str, strlen(str));
    close(fp);
    return NULL;
}

int main()
{
    std::cout << "The parent running!" << std::endl;
    pthread_t pt;
    pthread_create(&pt, NULL, Childer, NULL);
    std::cout << "The parent end!" << std::endl;
    sleep(10);
    return 0;
}