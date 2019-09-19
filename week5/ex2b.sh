#!/bin/bash
for ((i = 1; i <= 100000; i++))
do
	ln file.txt file.lock
	lastNumber="$(tail -n 1 file.txt)"
	echo $((lastNumber + 1)) >> file.txt 
	rm -f file.lock
done
