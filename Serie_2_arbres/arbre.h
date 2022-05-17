//
//  arbre.c
//  
//
//  Created by El Kahoui on 17/04/2021.
//

#include <stdio.h>
#include<stdlib.h>

struct noeud
{
    int cle;
    struct noeud * gauche;
    struct noeud * droit;
};
typedef struct noeud noeud;
typedef struct noeud * arbre;

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

int min(int x,int y){
    if(x>y)
        return y;
    return x;
}

/*int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(10,NULL,NULL);
    T2=faireArbre(2,NULL,NULL);
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
    arbre S=faireArbre(4,T,T1);
    printf("%d %d %d %d %d\n",S->cle,S->gauche->cle,S->gauche->gauche->cle,S->gauche->droit->cle, S->droit->cle);
    printf("Le maximum de l'arbre est %d\n\n",maximum(S));
    libererArbre(&T);
    return 0;
}
*/
