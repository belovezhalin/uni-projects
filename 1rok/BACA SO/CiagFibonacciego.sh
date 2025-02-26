#!/bin/bash                               #Anhelina Belavezha grupa nr 3

read linia
one=0
two=1
i=0

max=$linia
while [ $i -lt $max ]; do
  ((i++))
  echo "$one "
  wartosc=$((one+two))
  one=$two
  two=$wartosc
done
