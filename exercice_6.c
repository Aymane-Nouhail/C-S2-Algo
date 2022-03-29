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
	ajoutDebut(L->element,&L1);
	L = L->suivant;
	//affichageListe(L1);
	while(L!=NULL){
		//printf("%d\n",L->element);
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
