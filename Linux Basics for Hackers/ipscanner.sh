#! /bin/bash

# Script to find hosts with MySQL installed

echo "Enter the starting ip address:"

read FirstIP

echo "Enter the last ip address in the range to scan:"
read LastIP

echo "Enter the port number you want to scan for:"
read port

nmap -sT $FirstIP-$LastOctetIP -p $port >/dev/null -oG MySQLscan

cat MySQLscan3 | grep open > MySQLscan4

cat MySQLscan4