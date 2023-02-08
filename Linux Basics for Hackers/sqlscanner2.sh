#! /bin/bash

# Script to find hosts with MySQL installed

echo "Enter the starting ip address:"

read FirstIP

echo "Enter the last octet of the IP address:"
read LastOctetIP

echo "Enter the port number you want to scan for:"
read port

nmap -sT $FirstIP-$LastOctetIP -p $port >/dev/null -oG MySQLscan

cat MySQLscan | grep open > MySQLscan2

cat MySQLscan2