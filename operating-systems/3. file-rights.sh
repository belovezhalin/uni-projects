#!/bin/bash                                                     #Anhelina Belavezha

#Input
#The standard input consists of multiple lines, each representing the output of the ls -l command in its standard format.

#Output
#For each line of input, print the name of the file or directory along with its numeric permission representation.
#If the entry is a directory, append a / to its name.
#If the entry is a regular file and the owner has execute (x) permission, append a * to its name.
#The output order should match the input order.

read a
while read linia; do
  dlugosc=${#linia}
  i=0
  filename=""
  operation=0
  isfolder="F"
  isfile="F"
  permisions=""
  number=0
  symbol=" "

  while [ $i -le $dlugosc ]; do
    znak=${linia:$i:1}
    if [ $operation -eq 0 ]; then
      if [ $i -eq 4 ] || [ $i -eq 7 ] || [ $i -eq 10 ]; then
          permisions="$permisions$number"
          number=0
      fi

      if [ $i -eq 0 ]; then
        if [[ "$znak" = "d" ]]; then
          isfolder="T"
        fi

      elif [ $i -eq 1 ] || [ $i -eq 4 ] || [ $i -eq 7 ]; then
        if [[ "$znak" = "r" ]]; then
          ((number+=4))
        fi

      elif [ $i -eq 2 ] || [ $i -eq 5 ] || [ $i -eq 8 ]; then
        if [[ "$znak" = "w" ]]; then
          ((number+=2))
        fi

      elif [ $i -eq 3 ] || [ $i -eq 6 ] || [ $i -eq 9 ]; then
        if [[ "$znak" = "x" ]]; then
          ((number+=1))
          if [ $i -eq 3 ]; then
            isfile="T"
          fi
        fi
      fi

    elif [ $operation -eq 8 ]; then
      filename=$filename$znak
    fi
    
    if [[ "$znak" = " " ]] && [[ "$symbol" != " " ]]; then
      ((operation++))
    fi

  symbol=$znak
  ((i++))
  done
  
  znak=" "

  if [[ "$isfile" = "T" ]]; then
    znak="* "
  fi

  if [[ "$isfolder" = "T" ]]; then
    znak="/ "
  fi
  echo "$filename$znak$permisions"
done
