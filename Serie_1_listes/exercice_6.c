#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"

void inserer(int x, liste *L){
    cellule* C = (cellule*)malloc(sizeof(cellule));
    C->element = x;
    C->suivant = NULL;
    if(*L == NULL){ *L = C; return;}
    if(x<=(*L)->element){
        C->suivant=*L;
        *L = C;
        return;
    }
    liste temp=*L, temp1 = *L;
    while(temp!=NULL && x>temp->element){
        temp1 = temp;
        temp = temp->suivant;
    }
    temp1->suivant = C;
    C->suivant = temp;
    return;
}

liste trier(liste L){
	if(longueur(L)<=1) return L;
	liste L1 = NULL;
	while(L!=NULL){
		inserer(L->element,&L1);
		L = L->suivant;
	}
	return L1;
}

int main(){
	liste L = saisieListe(5);
	inserer(2,&L);
	affichageListe(L);
	liste C = saisieListe(5);
	liste L1 = trier(C); 
	affichageListe(C); affichageListe(L1);
	return 0;
}
