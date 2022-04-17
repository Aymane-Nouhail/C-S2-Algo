#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

void inserer(liste *L, int x){
	int n = longueur(*L);  
	if(n == 0){ajoutDebut(x,L); return;}
	if(x<=(*L)->element)
	{
		ajoutDebut(x,L);
		return;
	}
	liste temp=*L;
	liste temp1=temp;
	liste C=(liste)malloc(sizeof(cellule));
	C->element=x;
	C->suivant=NULL;
	while(temp!=NULL && temp->element<x)
	{
		temp1=temp;
		temp=temp->suivant;
	}
	temp1->suivant=C;
	C->suivant=temp;
	return;
}

liste trier(liste L){
	if(longueur(L)<=1) return L;
	liste L1 = NULL;
	while(L!=NULL){
		inserer(&L1,L->element);
		L = L->suivant;
	}
	return L1;
}

int main(){
	liste L = saisieListe(5);
	inserer(&L,2);
	affichageListe(L);
	liste C = saisieListe(5);
	liste L1 = trier(C);
	affichageListe(L1);
	return 0;
}
