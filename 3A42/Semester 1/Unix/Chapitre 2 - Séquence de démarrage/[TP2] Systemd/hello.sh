#! /bin/bash
echo "Hello everybody, we will give some informations about your OS" > /tmp/test.txt
var1=`find /etc/grub.d -type f -perm 755 | wc -w`
echo "-There are $var1 scripts template scripts used by GRUB2" >> /tmp/test.txt
var2=`grep ^menuentry /boot/grub/grub.cfg |wc -l`
echo "-There are $var2 GRUB2 menu entries ">> /tmp/test.txt
var3=`ps aux | wc -l`
echo "-There are $var3 process running on the machine" >> /tmp/test.txt 
