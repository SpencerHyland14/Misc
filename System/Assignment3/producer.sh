#!/bin/bash
#Gets the value from the storage text file
value=$(<storage.txt)
#Increases the value by 8
((value+=8))
#Checks to make sure the value is less than 100
if [ $value -lt 100 ]
then
    #Saves the new value to storage.txt
    echo "$value" > storage.txt
    #Prints the new value in terminal
    echo "from producer: Current total is $value"
    #Runs consumer.c
    ./a.out consumer.c
else
    #If greater than equal to 100 prints this message
    echo "from producer: Now I will take a rest!"
fi

