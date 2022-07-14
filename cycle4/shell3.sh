echo "enter a number to find factorial"
read n
i=`expr $n - 1`
while [ $i -ge 1 ]
do
n=`expr $n \* $i`
i=`expr $i - 1`
done
echo "the factorial of the given number is $n"
