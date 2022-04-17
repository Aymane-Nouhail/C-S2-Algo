#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

//////////////////////////////////////////////////////

void delete(int i, liste *L){
	if(*L == NULL) return;
	liste temp=*L;
	if(i==0){
		*L=(*L)->suivant;
		free(temp);
	}
	else{if(i<longueur(*L)){
	for(int k=0; k<i-1; k++) temp = temp->suivant;
	liste temp1 = temp->suivant;
	temp->suivant=temp1->suivant;
	free(temp1);
	}}
}

void ajouterIndice(int x, int i, liste *L){
	liste C=(cellule*)malloc(sizeof(cellule));
	C->element = x;
	if(*L == NULL){
        *L=C;
        C->suivant = NULL;
    }
	unsigned n = longueur(*L);
	if(i>n) i = n;
	liste temp = *L;
	for(int k=0; k<i-1; k++) temp = temp->suivant;
	liste temp_i=temp->suivant;
	temp->suivant = C;
	C->suivant = temp_i;
}
int main(){
	liste L =saisieListe(4);
	affichageListe(L);
	ajouterIndice(9,2,&L);
	affichageListe(L);
	delete(0,&L);
	affichageListe(L);
	return 0;
}
