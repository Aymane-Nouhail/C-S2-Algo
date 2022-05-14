#include<stdio.h>
#include<stdlib.h>
#include "file.h"


file copie(file F)
{
	int temp;
	file Q={NULL,NULL};
	while(F.debut!=NULL){
		temp = F.debut->element;
		enfiler(temp,&Q);
		F.debut = F.debut->suivant;
	}
	return Q;
}

//////////////////////////////////////////

int main()
{
    file F={NULL,NULL};
    enfiler(1,&F);
    enfiler(2,&F);
    enfiler(3,&F);
    affichage_file(F);
    /*defiler(&F);
    affichage_file(F);
    enfiler(6,&F);
    affichage_file(F);*/
    file C = copie(F);
    affichage_file(F);
    return 0;
}