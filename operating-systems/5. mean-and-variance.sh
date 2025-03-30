#!/bin/bash                             #Anhelina Belavezha

#Input
#Natural numbers in the range 1 to 100 are provided on standard input, each on a separate line. 
#Empty lines may also appear. There are no more than 50 numbers in total.

#Output
#The first line should print the arithmetic mean of the given numbers.
#The second line should print the variance.

i=0
suma=0
liczby=()
regex='^[0-9]+$'
while read linia; do
  if [[ $linia =~ $regex ]]; then
    liczby+=("$linia")
    suma=$((suma+linia))
    ((i++))
  fi
done

if [ $i -le 0 ]; then                  
  i=1
fi
srednia=$((suma/i))

j=0
max=${#liczby[@]}
sum=0
while [ $j -lt $max ]; do              
  one=$((liczby[j]-srednia))
  liczba=$((one**2))
  sum=$((sum+liczba))
  ((j++))
done
wariancja=$((sum/i))

echo $srednia
echo $wariancja
