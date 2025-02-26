#include <cstdio>
#include "UrzadzenieNaBaterie.h"

#ifndef __ODTWARZACZ_MULTIMEDIALNY_H__
#define __ODTWARZACZ_MULTIMEDIALNY_H__

class OM : public virtual UNB{
private:
	bool gry;	
	unsigned rozmiarEkranu;	
	
public:
	OM(unsigned ile, bool g=false, unsigned r=4): UNB(ile){
        gry=g;
        rozmiarEkranu=r;
		printf("Tworze OM\n");}
		
	~OM(){
		printf("Niszcze OM\n");}

    void przezentuj(){	
    	printf("Jestem odtwarzaczem\n");}	
    	
    bool getGry(){
         return gry;}		
         
    unsigned getRozmiarEkranu(){
         return rozmiarEkranu;}		
		
};

#endif

