#! /bin/bash

# Script to find hosts with MySQL installed

nmap -sT 100.115.92.197/28 -p 3306 >/dev/null -oG MySQLscan

cat MySQLscan | grep open > MySQLscan2

cat MySQLscan2