/*
 * @Descripttion:
 * @version:
 * @Author: Fang
 * @email: 2192294938@qq.com
 * @Date: 2021-11-10 22:30:31
 * @LastEditors: Fang
 * @LastEditTime: 2021-11-10 22:33:31
 */
#ifndef _LOCK_USAGE_TMIE_H_
#define _LOCK_USAGE_TMIE_H_

#include <sys/time.h>
#include <assert.h>

double Time_Get()
{
    struct timeval t;
    assert(gettimeofday(&t, nullptr) == 0);
    return (double)((double)t.tv_sec + (double)t.tv_usec / 1e6);
}

#endif