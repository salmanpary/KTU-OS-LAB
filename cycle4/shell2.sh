echo "enter the year to check leap year"
read leapyear
b=`expr $leapyear % 4`
if [ $b -eq 0 ] 
then
echo "$leapyear is a leap year"
else
echo "$leapyear is not a leap year"
fi
