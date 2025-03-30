#!/bin/bash                       #Anhelina Belavezha

#Input
#Identifiers are provided on standard input, each on a separate line. Identifiers may repeat.

#Output
#The script should find the identifier that appears the fewest times and print it along with its occurrence count (on a single line).
#If multiple identifiers have the same minimum count, print the one that appeared first in the input.

declare -A assoc
kolejka=()
i=0
while read linia; do              
  ((assoc[$linia]++))
  kolejka[$i]=$linia
  ((i++))
done

max=$i
min=10000
i=0
while [ $i -le $max ]; do   
  if [ ${assoc[${kolejka[$i]}]} -lt $min ]; then
    min=${assoc[${kolejka[$i]}]}
    nazwamin=${kolejka[$i]}
  fi
  ((i++))
done

echo "$nazwamin ${assoc[$nazwamin]}"
