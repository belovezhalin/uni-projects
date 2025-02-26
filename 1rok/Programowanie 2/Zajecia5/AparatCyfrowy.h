#include <cstdio>
#include "UrzadzenieNaBaterie.h"

#ifndef __APARAT_CYFROWY_H__
#define __APARAT_CYFROWY_H__

class AC : public virtual UNB{
private:
	unsigned megapiksele;
	unsigned zoom;	
	
public:
	AC(unsigned ile, unsigned m=8, unsigned z=6): UNB(ile){
        megapiksele=m;
        zoom=z;
		printf("Tworze AC\n");}
		
	~AC(){
		printf("Niszcze AC\n");}
		
    void przezentuj(){	
    	printf("Jestem aparatem\n");}
    	    	
    unsigned getMegapiksele(){
         return megapiksele;}		
         
    unsigned getZoom(){
         return zoom;}	
};

#endif

