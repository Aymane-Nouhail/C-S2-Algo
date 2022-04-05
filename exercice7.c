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

//parenthese function

int parenthese(char ch[]){
	pile P = NULL;
	int n = strlen(ch);
	for(int i=0;i<n;i++){
		if(ch[i] =='(') empiler(1,&P);
		if(ch[i] ==')'){
			if(estVide(P) == 1) return 0;
			else depiler(&P);
		}
	}
	if(estVide(P) == 1) return 1;
	liberer(P);
	return 0;
}

//concatenate two chars

int parentheseCrochets(char ch[]){
	pile P = NULL;
	int n = strlen(ch);
	for(int i=0;i<n;i++){
		if(ch[i] == '(') empiler(0,&P);
		if(ch[i] == '[') empiler(1,&P);
		if(ch[i] == ')'){
			if(P->element == 1) return 0;
			else depiler(&P);
		}
		if(ch[i] == ']'){
			if(P->element == 0) return 0;
			else depiler(&P);
		}
	}
	if(estVide(P) == 1) return 1;
	liberer(P);
	return 0;
	
}


int main()
{
    printf("\nVeuillez donner une chaine de caracteres.\n\n");
    char ch[100];
    scanf("%s", ch);
    if(parentheseCrochets(ch))
        printf("parentheses bien formatees\n\n");
    else
        printf("parentheses mal formatees\n\n");
}
