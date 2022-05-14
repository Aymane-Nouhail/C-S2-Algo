#include<stdio.h>
#include<stdlib.h>
#include "pile.h"

//copie inverse function

pile copie_inverse(pile P){
	int temp;
	pile Q=NULL;
	while(P!=NULL){
		temp = P->element;
		empiler(temp,&Q);
		P = P->suivant;
	}
	return Q;
}

pile copie(pile P){
	pile Q1 = copie_inverse(P);
	pile Q2 = copie_inverse(Q1);
	liberer(Q1);
	return Q2;
}
int main(){
	pile P = NULL;
	empiler(1,&P); empiler(2,&P); empiler(3,&P); empiler(4,&P);
	affichage_pile(P);
	pile Q = copie(P);
	affichage_pile(Q);
	//affichage_pile(P);
	return 0;
}
