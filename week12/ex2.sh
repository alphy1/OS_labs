#!/bin/bash

gcc ex2.c
cat /proc/cpuinfo | ./a.out ex2.txt
