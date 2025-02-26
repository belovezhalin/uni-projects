#!/bin/bash                       #Anhelina Belavezha grupa nr 3

declare -A assoc
kolejka=()
i=0
while read linia; do              #odczytanie linijek
  ((assoc[$linia]++))
  kolejka[$i]=$linia
  ((i++))
done

max=$i
min=10000
i=0
while [ $i -le $max ]; do         #ustawienie minimalnej wartosci wystapienia
  if [ ${assoc[${kolejka[$i]}]} -lt $min ]; then
    min=${assoc[${kolejka[$i]}]}
    nazwamin=${kolejka[$i]}
  fi
  ((i++))
done

echo "$nazwamin ${assoc[$nazwamin]}"
