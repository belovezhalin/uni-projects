//Anhelina Belavezha
#include <string>
using namespace std;

string FormatujNapis (string napis, string arg1, string arg2, string arg3) {
	
  string zwrot = "";
  
  for (int i = 0; i < napis.size(); i++) {
    if (napis[i] == '{') {
    	switch (napis[i + 1]) {
    		case 'p':
    			for (int p = 0; p < napis[i + 3] - '0'; p++) {zwrot += napis[i + 5];};
    			i += 6;
    		break;
    		
    		case 'u':
    			if (i + napis[i + 3] - '0' + 4 > napis.size()) i = napis.size();  
				else i += napis[i + 3] - '0' + 4;  	
			break;
    		
    		case 'U':
    			if ((int)zwrot.size() - napis[i + 3] + '0' < 0) zwrot = "";
    			else zwrot.resize(zwrot.size() - napis[i + 3] + '0');
    			i += 4;
    		break;
    		
    		case 'w':
    			if (napis[i + 3] == '1') zwrot += arg1;
    			else if (napis[i + 3] == '2') zwrot += arg2;
    			else if (napis[i + 3] == '3') zwrot += arg3;
    			i += 4;
    		break;
    		
    		case 'W':
    			string argument = "";
    			if (napis[i + 3] == '1') argument = arg1;
    			else if (napis[i + 3] == '2') argument = arg2;
    			else if (napis[i + 3] == '3') argument = arg3;
    			
    			if (argument.size() < napis[i + 5] - '0') {
    				for (int a = argument.size(); a < napis[i + 5] - '0'; a++) argument += ' ';}
    			else if (napis[i + 5] - '0' < argument.size()) argument.resize(napis[i + 5] - '0');
    			
    			zwrot += argument;
    			i += 6;
    		break;}}
    else if (napis[i] != 0) zwrot += napis[i];}
  
return zwrot;}

string NajwiekszeSlowo (string napis) {

  string zwrot = "";
  string czyt = "";
  
  for (int i = 0; i < napis.size(); i++) {
  	if (napis[i] != ' ') czyt += napis[i];
	  
	if (i == napis.size() - 1 || napis[i] == ' ') {
  		if (zwrot < czyt) zwrot = czyt;
  		czyt = "";}}
  		
return zwrot;}

string NormalizujNapis (string napis) {
	
  string zwrot = "";
  bool slowo = true;
  int i = 0;
  
  while (napis[i] == ' ') {i++;}
  
  for (; i < napis.size(); i++) {
  	if (napis[i] != ' ' && napis[i] != ',' && napis[i] != '.') {
  		if (slowo == false) {zwrot += ' '; zwrot += napis[i];}
  		else zwrot += napis[i];}
	else if (napis[i] == '.' || napis[i] == ',') zwrot += napis[i];
	
	slowo = napis[i] != ' ' && napis[i] != '.' && napis[i] != ',';}

return zwrot;}

string UsunSlowo (string napis, int liczba) {
	
  string zwrot = "";
  bool slowo = false;
  int numer = 1;
  
  for (int i = 0; i < napis.size(); i++) {
  	if (napis[i] == ' ' && slowo == true) numer++;
  	
  	slowo = napis[i] != ' '; 
  	
  	if (!slowo || liczba != numer) zwrot += napis[i];}
  	
return zwrot;}

