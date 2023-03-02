!/bin/sh

sudo apt install gcc-multilib
gcc -o hacked hacked.c -fno-stack-protector -m32 -no-pie
