#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

//////////////////////////////////////////////////////

void delete(int i, liste *L){
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
	liste temp = *L;
	unsigned n = longueur(*L);
	if(i>n) i = n;
	for(int k=0; k<i-1; k++) temp = temp->suivant;
	liste C=(cellule*)malloc(sizeof(cellule));
	liste temp_i=temp->suivant;
	C->element = x;
	temp->suivant = C;
	C->suivant = temp_i;
}
int main(){
	liste L = saisieListe(3);
	affichageListe(L);
	ajouterIndice(9,2,&L);
	affichageListe(L);
	delete(2,&L);
	affichageListe(L);
	return 0;
}
