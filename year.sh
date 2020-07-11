#!/bin/bash

if date -d "29 feb" >/dev/null 2>&1
	then
		days=366
	else
		days=365
	fi

day=$(( $(date +%j) * 100 ))

percentage=$(( $day / $days ))

echo $(date +%Y), Q$(date +%q) \($percentage\% complete\) 
