#!/bin/bash                               #Anhelina Belavezha

#Input
#A natural number 1 <= n <= 50 is given on standard input.

#Output
#Print the first n terms of the Fibonacci sequence, one per line.
#The sequence starts with 0 as the first term and 1 as the second term.

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
