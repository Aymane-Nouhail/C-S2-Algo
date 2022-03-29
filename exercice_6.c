#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

void inserer(liste *L, int x){
	int n = longueur(*L);  
	if(n == 0){ajoutDebut(x,L); return;}
	if(n == 1){
		if(x > (*L)->element) ajoutFin(x,L);
		else ajoutDebut(x,L);
		return;
	}
	cellule* C = (cellule*)malloc(sizeof(cellule));
	C->element = x;
	liste temp = *L;
	while(x > temp->suivant->element)
		temp = temp->suivant;
	liste temp1 = temp->suivant;
	temp->suivant = C;
	C->suivant = temp1;
	return;
}

liste trier(liste L){
	if(longueur(L)<=1) return L;
	liste L1 = NULL;
	ajoutDebut(L->element,&L1);
	L = L->suivant;
	//affichageListe(L1);
	while(L!=NULL){
		printf("%d\n",L->element);
		inserer(&L1,L->element);
		//affichageListe(L1);
		L = L->suivant;
	}
	return L1;
}

int main(){
	liste L = saisieListe(5);
	inserer(&L,2);
	affichageListe(L);
	liste L1 = trier(L);
	affichageListe(L1);
	
}
