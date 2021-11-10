'''
Descripttion: 
version: 
Author: Fang
email: 2192294938@qq.com
Date: 2021-11-10 22:50:00
LastEditors: Fang
LastEditTime: 2021-11-10 22:54:52
'''
import os
import re
import matplotlib.pyplot as plt

res = os.popen('./out/q2').read()
y = [float(r) for r in re.findall(r'\d\.\d*', res)]
plt.plot(range(1,9), y)
plt.xlabel('cpu count')
plt.ylabel('time')
plt.xlim(1, 8)
plt.show()
