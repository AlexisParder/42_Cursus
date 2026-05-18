#!/bin/bash
architecture=$(uname -a)

cpu_p=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)

vcpu=$(grep "processor" /proc/cpuinfo | sort | uniq | wc -l)

mem_use=$(free -m | grep "Mem" | awk '{print $3}')
mem_tot=$(free -m | grep "Mem" | awk '{print $2}')
mem_percent=$(awk "BEGIN {printf int(($mem_use/$mem_tot)*100)}")

disk_use=$(df -BG --total | grep "total" | awk '{print $3}' | tr -d 'G')
disk_tot=$(df -BG --total | grep "total" | awk '{print $4}' | tr -d 'G')
disk_percent=$(awk "BEGIN {printf int(($disk_use/$disk_tot)*100)}")

cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_use=$(awk "BEGIN {printf int((100-$cpul))}")

last_boot=$(uptime -s)

lvm_use="no"
if (lsblk | grep -q "lvm") then
	lvm_use="yes"
fi

connection_tcp=$(ss | grep "tcp" | wc -l)

user_log=$(users | wc -w)

ip=$(hostname -I | awk '{print $1}')
address_mac=$(ip link show | grep "ether" | awk '{print $2; exit}')

sudo_cmd=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall "
#Architecture: $architecture
#CPU Physical: $cpu_p
#vCPU: $vcpu
#Memory Usage: $((mem_use))/$((mem_tot))MB ($((mem_percent))%)
#Disk Usage: $((disk_use))/$((disk_tot))Gb ($((disk_percent))%)
#CPU Load: $cpu_use %
#Last Boot: $last_boot
#LVM Use: $lvm_use
#Connections TCP: $connection_tcp ESTABLISHED
#User Log: $user_log
#Network: IP $ip ($address_mac)
#Sudo: $sudo_cmd cmd"
