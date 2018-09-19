#!/bin/bash
touch input

while ! ln input input.lock; do
	sleep 1
done

if [ ! -f input ]; then echo 0 > input; fi
count=0
while [ $count -lt 2000 ]; do
	count=$(expr $count + 1)
        lastDigit=$(tail -1 input)
	nextDigit=$(expr $lastDigit + 1)
        echo $nextDigit >> input
done
rm input.lock

