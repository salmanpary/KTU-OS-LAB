#!/bin/sh
echo "Enter the number to check whether it is odd or even"
read n
r=`expr $n % 2`
if [ $r -eq 0 ]
then
echo "$n is an Even number"
else
echo "$n is odd number"
fi 


