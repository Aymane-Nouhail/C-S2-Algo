//
//  arbre.c
//  
//
//  Created by El Kahoui on 17/04/2021.
//

#include <stdio.h>
#include<stdlib.h>
#include "parcours.h"
/*struct noeud
{
    int cle;
    struct noeud * gauche;
    struct noeud * droit;
};
typedef struct noeud noeud;
typedef struct noeud * arbre; */

// Prototypes
arbre arbreVide(); /*Construit un arbre vide*/
int testVide(arbre); /*Teste si un arbre est vide*/
int racine(arbre); /*Extrait la racine de l'arbre*/
arbre gauche(arbre);/*Extrait le sous-arbre gauche*/
arbre droit(arbre); /*Extrait le sous-arbre droit*/
arbre faireArbre(int, arbre,arbre); /* construit un arbre a partir d'une racine et de deux arbres */
void fixerCle(int, arbre *); /*Modifie la racine d'un arbre*/
void fixerGauche(arbre, arbre *); /*Modifie le sous-arbre gauche */
void fixerDroit(arbre, arbre *); /* Modifie le sous-arbre droit*/
void libererArbre(arbre *); /* libere la zone memoire*/
/* Implementation de la file d'arbres*/

int estVideFile(file_arbre F)
{
    if(F.longueur==0)
        return 1;
    return 0;
}

void enfiler(arbre T, file_arbre * F)
{
    if(F->longueur==N)
    {
        printf("File pleine !\n");
        return;
    }
    F->tete[F->longueur]=T;
    F->longueur+=1;
    return;
}

arbre defiler(file_arbre * F)
{
    if(estVideFile(*F))
    {
        return NULL;
    }
    arbre T=F->tete[0];
    int i;
    for(i=1;i<F->longueur;i++)
        F->tete[i-1]=F->tete[i];
    F->longueur-=1;
    return T;
}


/* Implementation de la pile d'arbres*/

int estVidePile(pile_arbre P)
{
    if (P.longueur ==0)
        return 1;
    return 0;
}

void empiler(arbre T,pile_arbre * P)
{
    if(P->longueur==N)
    {
        printf("Pile vide.\n");
        return;
    }
    P->tete[P->longueur]=T;
    P->longueur+=1;
}

arbre depiler(pile_arbre * P)
{
    if(estVidePile(*P))
        return NULL;
    arbre T=P->tete[P->longueur-1];
    P->longueur-=1;
    return T;
}

// Implementations
// Arbre vide 
arbre arbreVide()
{
    arbre T=NULL;
    return T;
}

// Test à vide d'un arbre
int estVide(arbre T)
{
    if(T==NULL)
        return 1;
    return 0;
}

// Racine
 int racine(arbre T)
{
    if(estVide(T))
       exit(EXIT_FAILURE);
    return T->cle;
}

// Sous-arbre gauche
arbre gauche(arbre T)
{
    if(estVide(T))
        return NULL;
    return T->gauche;
}

// Sous-arbre droit
arbre droit(arbre T)
{
    if(estVide(T))
        return NULL;
    return T->droit;
}

// faireArbre
arbre faireArbre(int x,arbre T_1,arbre T_2)
{
    arbre T=(arbre)malloc(sizeof(noeud));
    T->cle=x;
    T->gauche=T_1;
    T->droit=T_2;
    return T;
}

// fixerCle
void fixerCle(int x,arbre * P)
{
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->cle=x;
        //return *P;
    }
}

// fixerGauche
void fixerGauche(arbre G, arbre * P)
{
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        
        (*P)->gauche=G;
        //return *P;
    }
}

// fixerDroit
void fixerDroit(arbre D, arbre * P)
{
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        
        (*P)->droit=D;
        //return *P;
    }
}

// Liberer
void libererArbre(arbre *T)
{
    arbre temp=*T;
    if(temp==NULL)
        return;
    if(temp->gauche!=NULL)
        libererArbre(&temp->gauche);
    if(temp->droit!=NULL)
        libererArbre(&temp->droit);
    free(temp);
    *T=NULL;
}

int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int maximum(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    if(T->gauche==NULL && T->droit==NULL)
        return T->cle;
    if(T->gauche==NULL)
        return max(T->cle,maximum(T->droit));
    if(T->droit==NULL)
        return max(T->cle,maximum(T->gauche));
    return max(T->cle,max(maximum(T->gauche),maximum(T->droit)));
}

int somme(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    if(T->gauche==NULL && T->droit==NULL)
        return T->cle;
    if(T->gauche==NULL)
        return T->cle + somme(T->droit);
    if(T->droit==NULL)
        return T->cle + somme(T->gauche);
    return T->cle + somme(T->droit) + somme(T->gauche);
}

int taille(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    if(T->gauche==NULL && T->droit==NULL)
        return 1;
    if(T->gauche==NULL)
        return 1 + taille(T->droit);
    if(T->droit==NULL)
        return 1 + taille(T->gauche);
    return 1 + taille(T->droit) + taille(T->gauche);	
}

int noeuds_interne_recursive(arbre T)
{
    if(T==NULL)
        return 0;
    if(T->gauche==NULL && T->droit==NULL)
        return 0;
    return 1 + noeuds_interne_recursive(T->droit) + noeuds_interne_recursive(T->gauche);;	
}

int feuilles_recursive(arbre T)
{
    if(T==NULL)
        return 0;
    if(T->gauche==NULL && T->droit==NULL)
        return 1;
    return feuilles_recursive(T->gauche) + feuilles_recursive(T->droit);
}

int Noeuds_internes_parcours(arbre T)
{
    if(T==NULL)
        return 0;
    file_arbre F={NULL,0};
    arbre temp=T;
    enfiler(T,&F);
    int s=0;
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        if(temp->gauche!=NULL || temp->droit!=NULL)
        	s=s+1;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return s;
}

int feuilles_parcours(arbre T)
{
    if(T==NULL)
        return 0;
    file_arbre F={NULL,0};
    arbre temp=T;
    enfiler(T,&F);
    int s=0;
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        //printf("%d ",s);
        if(temp->gauche==NULL || temp->droit==NULL)
        	s=s+1;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return s;
}


int strahler(arbre T)
{
    if(T==NULL)
         return 0;
    if(strahler(T->droit)==strahler(T->gauche))
    	return strahler(T->droit)+1;
    else
    	return max(strahler(T->droit),strahler(T->gauche));		
}

int abr(arbre T)
{
	if(T==NULL)
		return 1;
	if((T->gauche!=NULL && T->cle<(T->gauche)->cle))
		return 0;
	if((T->droit!=NULL && T->cle>(T->droit)->cle))
		return 0;
	return abr(T->gauche) && abr(T->droit);
}

int rechercher(int x, arbre T)
{
	if(T==NULL)
		return 0;
		
}


int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    arbre T3=NULL;
    T1=faireArbre(100,NULL,NULL);
    T2=faireArbre(2,NULL,NULL);
    T3=faireArbre(12,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
    printf("\nAffichage : racine, fils gauche, fils droit.\n");
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du contenu de la racine.\n");
    fixerCle(5,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du sous-arbre gauche.\n");
    fixerGauche(T2,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du sous-arbre droit.\n");
    fixerDroit(T1,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    arbre S=faireArbre(10,T,T1);
    fixerDroit(T3, &S);
    printf("%d %d %d %d %d\n",S->cle,S->gauche->cle,S->gauche->gauche->cle,S->gauche->droit->cle, S->droit->cle);
    printf("Le maximum de l'arbre est %d\n\n",maximum(S));
    printf("la somme des elements: %d \n",somme(S));
    printf("la taille des elements: %d \n",taille(S));
    printf("LEs noeuds internes RECURSIVES: %d \n", noeuds_interne_recursive(S));
    printf("nombre de feuilles par recurrence: %d \n", feuilles_recursive(S));
    printf("nombre de noeuds internes par parcours : %d \n", Noeuds_internes_parcours(S));
    printf("nombre de feuilles par parcours: %d \n", feuilles_parcours(S));
    printf("Strahler number %d \n", strahler(S));
    printf("abr %d\n", abr(S));
    libererArbre(&T);
    return 0;
}


