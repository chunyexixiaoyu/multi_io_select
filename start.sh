#!/bin/bash
chmod +x ./*
declare -i i=1
num_process=30 ## process number  user can set
echo   "set prcocess number is " $num_process
#./server &
#sleep 5s
while(($i<=$num_process))
do
##echo "start up process :"$i
    i=$i+1
    ./client &
done








