#!/bin/bash

echo 'hex value: '
read $x
[ "$x" -gt 127 ] && ((x=x-256)) 
echo "$x"
