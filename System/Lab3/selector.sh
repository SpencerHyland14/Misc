#!/bin/bash


input1=`grep -n $1<headandtail.txt | cut -b1 | head -n1`
input2=`grep -n $2<headandtail.txt | cut -b1 | head -n1`
head -n$input2 headandtail.txt | tail -n$((input1-input2-1))
	
if [ $input1 -gt $input2 ]
then
echo The first word entered is after the second
fi