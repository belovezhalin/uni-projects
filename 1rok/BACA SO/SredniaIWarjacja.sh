#!/bin/bash                             #Anhelina Belavezha grupa nr 3

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

if [ $i -le 0 ]; then                  #srednia
  i=1
fi
srednia=$((suma/i))

j=0
max=${#liczby[@]}
sum=0
while [ $j -lt $max ]; do              #warjacja
  one=$((liczby[j]-srednia))
  liczba=$((one**2))
  sum=$((sum+liczba))
  ((j++))
done
wariancja=$((sum/i))

echo $srednia
echo $wariancja
