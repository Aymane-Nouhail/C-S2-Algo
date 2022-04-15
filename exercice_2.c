#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

//1st and 2nd questions are in liste_simple.h
int distinctNum(liste L){
	int n = 0;
	liste C = NULL;
	while(L != NULL){
		if(recherche(L->element,C)==NULL){ajoutDebut(L->element,&C); n++;}
		L = L->suivant;
	}
	return n;
}
int main(){
	liste L = saisieListe(4);
	affichageListe(L);
	//affichageListe(recherche(5,L));
	//printf("%d\n", occurence(5,L));
	printf("%d\n", distinctNum(L));
	//affichageListe(distinctNum(L));
}
