.main
.top        ;标号
sub  $1,%dx ;dx寄存器值减一，结果存入dx
test $0,%dx ;比较dx寄存器的值与0
jgte .top   ;如果dx寄存器的值大于或等于0则跳到top     
halt        ;结束线程