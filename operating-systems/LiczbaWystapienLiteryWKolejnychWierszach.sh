#!/bin/bash                                                  #Anhelina Belavezha grupa nr 3
read litera
equal="true"

if [[ ${litera:1:1} == "=" ]]; then
   equal="false"
fi

litera=${litera:0:1}
literawielka=$(echo "$litera" | tr /a-z/ /A-Z/)                             #ustawienie wielkiej litery

while read wiersz; do
  dlugosc=${#wiersz}
  i=0
  resultat=0
  while [ $i -lt $dlugosc ]; do
    znak=${wiersz:$i:1}
    ((i++))
    if [ "$equal" = true ] && [[ "$znak" = "$literawielka" ]]; then        #wystapienie litery
      ((resultat++))
    elif [[ "$znak" = "$litera" ]]; then                                   #wystapienie dokladnie takiej litery
      ((resultat++))
    fi
  done
  echo $resultat
done