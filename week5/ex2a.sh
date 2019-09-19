#!/bin/bash
for ((i = 1; i <= 10000000; i++))
do
	lastNumber="$(tail -n 1 file.txt)"
	echo $((lastNumber + 1)) >> file.txt 
done
