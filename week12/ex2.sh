# no /proc/cpuinfo on mac os, replaced with sysctl
gcc ex2.c -o ex2
sysctl -a | grep machdep.cpu | ./ex2 ex2.txt
rm ex2
