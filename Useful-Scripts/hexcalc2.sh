#!/bin/bash

echo 'Format: <1stInput> - <2ndInput>'
echo 'Remember to include 0x'

# Read first value
echo 'Enter 1st hex valuen>> '
read hex_a

# Select Operand
echo 'Add (+), Subtract (-),'
echo 'or multiply(*)'
read operand

# Enter second value
echo 'Enter 2nd hex value>> '
read hex_b

echo '"+", "-", "*"'
read operand2

echo 'Enter 3rd hex value>> '
read hex_c

echo '"+", "-", "*"'
read operand3

echo 'Enter 4th hex value>> '
read hex_d

printf "0x%X\n" $(($hex_a $operand $hex_b $operand2 $hex_c $3 $operand3 $hex_d))
