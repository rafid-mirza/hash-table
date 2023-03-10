#!/bin/bash

#Rafid Mirza
#rm2jgk
#10/19/21
#averagetime.sh

#Prompt user for inputs (read docs found at: https://linuxhint.com/bash_read_command/)
read DICTIONARY

read GRID

#Run program 5 times
RUNNING_TIME_1=`./a.out ${DICTIONARY} ${GRID}| tail -1`
RUNNING_TIME_2=`./a.out ${DICTIONARY} ${GRID}| tail -1`
RUNNING_TIME_3=`./a.out ${DICTIONARY} ${GRID}| tail -1`
RUNNING_TIME_4=`./a.out ${DICTIONARY} ${GRID}| tail -1`
RUNNING_TIME_5=`./a.out ${DICTIONARY} ${GRID}| tail -1`

#Calculate average running times and print out
sum=$(($RUNNING_TIME_1 + $RUNNING_TIME_2 + $RUNNING_TIME_3 + $RUNNING_TIME_4 + $RUNNING_TIME_5)) 
AVERAGE_TIME=$((sum / 5))
echo ${AVERAGE_TIME}