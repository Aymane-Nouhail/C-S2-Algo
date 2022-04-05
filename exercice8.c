//
//  pile.c
//  
//
//  Created by El Kahoui on 27/01/2021.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cellule
{
    int element;
    struct cellule * suivant;
};
typedef struct cellule cellule;
typedef cellule * pile;

// Prototypes
int estVide(pile);
int lire(pile);
void empiler(int,pile *);
int depiler(pile *);
void affichage_pile(pile);
void liberer(pile);


// Pile vide

int estVide(pile P)
{
    if(P==NULL)
        return 1;
    return 0;
}

// Lecture
int lire(pile P)
{
    if(estVide(P)==0)
        return P->element;
    else
        exit(EXIT_FAILURE);
}

// Empilement d'une pile
void empiler(int x,pile *P)
{
    pile C=(pile)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=*P;
    *P=C;
}

// Depilage

int depiler(pile * P)
{
    if(estVide(*P)==0)
    {
        int res=(*P)->element;
        pile temp=*P;
        *P=(*P)->suivant;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}

// Affichage

void affichage_pile(pile P)
{
    pile temp=P;
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d\n",temp->element);
}

// Liberation
void liberer(pile P)
{
    while(P!=NULL)
    {
        pile temp=P;
        P=P->suivant;
        free(temp);
    }
}

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
