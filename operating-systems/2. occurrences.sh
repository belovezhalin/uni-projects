#!/bin/bash                                                  #Anhelina Belavezha
read litera
equal="true"

#Input
#The first line of standard input contains a letter [A-Za-z] (without Polish characters) and optionally an equals sign (=). 
#The following lines contain words or sentences composed of uppercase and lowercase letters, or they may be empty lines.

#Output
#For each input line (excluding the first one, which specifies the letter to search for), print the number of occurrences of the specified letter.
#If the first line does not contain an equals sign (=), count occurrences of the letter case-insensitively.
#If the first line does contain an equals sign (=), count occurrences of the letter exactly as given.

if [[ ${litera:1:1} == "=" ]]; then
   equal="false"
fi

litera=${litera:0:1}
literawielka=$(echo "$litera" | tr /a-z/ /A-Z/)                             

while read wiersz; do
  dlugosc=${#wiersz}
  i=0
  resultat=0
  while [ $i -lt $dlugosc ]; do
    znak=${wiersz:$i:1}
    ((i++))
    if [ "$equal" = true ] && [[ "$znak" = "$literawielka" ]]; then        
      ((resultat++))
    elif [[ "$znak" = "$litera" ]]; then                                  
      ((resultat++))
    fi
  done
  echo $resultat
done
