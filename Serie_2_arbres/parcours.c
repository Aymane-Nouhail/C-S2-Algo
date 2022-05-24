#include <stdio.h>
#include<stdlib.h>



/* La structure arbre*/
struct noeud
{
    int cle;
    struct noeud * gauche;
    struct noeud * droit;
};
typedef struct noeud noeud;
typedef struct noeud * arbre;

#define N 200
/* La file d'arbres implementée à l'aide d'un tableau*/
struct file_arbre
{
    arbre tete[N];
    unsigned longueur;
};
typedef struct file_arbre file_arbre;


/* La pile d'arbres implementée à l'aide d'un tableau*/
struct pile_arbre
{
    arbre tete[N];
    unsigned longueur;
};
typedef struct pile_arbre pile_arbre;

/* Le tableau dynamique */
struct tableau
{
    unsigned taille;
    int *tete;
};
typedef struct tableau tableau;

                        /* Interface Prototypes */

/* Implementation de l'arbre*/
// Arbre vide
arbre arbreVide()
{
    arbre T=NULL;
    return T;
}

// Test à vide d'un arbre
int estVideArbre(arbre T)
{
    if(T==NULL)
        return 1;
    return 0;
}

// Racine
 int racine(arbre T)
{
    if(estVideArbre(T))
       exit(EXIT_FAILURE);
    return T->cle;
}

// Sous-arbre gauche
arbre gauche(arbre T)
{
    if(estVideArbre(T))
        return NULL;
    return T->gauche;
}

// Sous-arbre droit
arbre droit(arbre T)
{
    if(estVideArbre(T))
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
    if(estVideArbre(*P))
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
    if(estVideArbre(*P))
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
    if(estVideArbre(*P))
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


/* Implementation de la file d'arbres */

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
        printf("Pile pleine.\n");
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

/* Implementation du tableau */
tableau  creer(unsigned n)
{
    tableau T;
    T.taille=n;
    T.tete=(int *)malloc(n*sizeof(int));
    return(T);
}

//La procédure affichage

void affichageTableau(tableau T)
{
    
    if(T.tete==NULL)
    printf("[]");
    else
    {
        unsigned n=T.taille;
        printf("[");
        for(int i=0;i<n-1;i++)
            printf("%d,",T.tete[i]);
        printf("%d]",T.tete[n-1]);
    }
    printf("\n");
    return;
}

//La procédure saisie
void saisieTableau(tableau T)
{
    if(T.tete==NULL)
        printf("Tableau vide !\n");
    else
    {
        for(int i=0;i<T.taille;i++)
            scanf("%d",T.tete+i);
    }
    return;
}

//La procédure liberer
void libererTableau(tableau T)
{
    if(T.tete!=NULL)
        free(T.tete);
    return;
}


                        /****** Parcours ****/

// Affichage avec parcours en largeur

void affichageLargeur(arbre T)
{
    if(T==NULL)
        return;
    file_arbre F;
    F.longueur=0;
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        printf("%d ",temp->cle);
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    printf("\n");
}

void affichagePrefixe(arbre T)
{
    if(T==NULL)
        return;
    pile_arbre P;
    P.longueur=0;
    arbre temp=T;
    empiler(T,&P);
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        printf("%d ",temp->cle);
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return;
}

unsigned tailleLargeur(arbre T)
{
    if(T==NULL)
        return 0;
    unsigned n=0;
    file_arbre F={NULL,0};
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        n+=1;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return n;
}

tableau arbreTableauInfixe(arbre T)
{
    if(T==NULL)
    {
        tableau T={0,NULL};
        return T;
    }
    unsigned n=tailleLargeur(T);
    tableau L=creer(n);
    unsigned i=0;
    pile_arbre P={NULL,0};
    arbre temp=T;
    while(estVidePile(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            empiler(temp,&P);
            temp=temp->gauche;
        }
        else
        {
            temp=depiler(&P);
            L.tete[i]=temp->cle;
            i+=1;
            temp=temp->droit;
        }
    }
    return L;
}


int maximum(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    pile_arbre P;
    P.longueur=0;
    arbre temp=T;
    empiler(T,&P);
    int m=T->cle;
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        if(temp->cle>m)
            m=temp->cle;
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return m;
}

unsigned feuilles(arbre T)
{
    if(T==NULL)
        return 0;
    unsigned n=0;
    file_arbre F;
    F.longueur=0;
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        if(temp->gauche==NULL && temp->droit==NULL)
            n++;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return n;
}


double moyenne(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    unsigned n=0;
    int S=0;
    file_arbre F;
    F.longueur=0;
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        n++;
        S+=temp->cle;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return (double)S/n;
}

arbre recherche(int x, arbre T)
{
    if(T==NULL)
        return NULL;
    file_arbre F;
    F.longueur=0;
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        if(x==temp->cle)
            return temp;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return NULL;
}





int testAbrInfixe(arbre T)
{
    if(T==NULL)
        return 1;
    tableau L=arbreTableauInfixe(T);
    for(int i=0;i<L.taille-1;i++)
    {
        if(L.tete[i+1]<=L.tete[i])
            return 0;
    }
    return 1;
}

arbre rechercheAbr(int val,arbre T)
{
    arbre temp=T;
    while(estVideArbre(temp)==0 && val!=temp->cle)
    {
        if(val<temp->cle)
            temp=temp->gauche;
        if(val>temp->cle)
            temp=temp->droit;
    }
    return temp;
}

void insererAbrRecursive(int val,arbre * T)
{
    if(*T==NULL)
    {
        *T=faireArbre(val,NULL,NULL);
        return;
    }
    if(val==(*T)->cle)
        return;
    if(val<(*T)->cle)
        insererAbrRecursive(val,&(*T)->gauche);
    if(val>(*T)->cle)
        insererAbrRecursive(val,&(*T)->droit);
}

void insererAbrIterative(int val, arbre * T)
{
    if(*T==NULL)
    {
        *T=faireArbre(val,NULL,NULL);
    }
    arbre temp=*T;
    arbre temp1=*T;
    while(temp!=NULL)
    {
        temp1=temp;
        if(val==temp->cle)
            return;
        if(val<temp->cle)
            temp=temp->gauche;
        else
            temp=temp->droit;
    }
    if(val==temp1->cle)
        return;
    if(val<temp1->cle)
        temp1->gauche=faireArbre(val,NULL,NULL);
    else
        temp1->droit=faireArbre(val,NULL,NULL);
    return;
}

void suppressionAbrRecursive(int val,arbre *T)
{
    if(*T==NULL)
        return;
    if(val==(*T)->cle)
    {
        arbre temp=*T;
        if((*T)->gauche==NULL && (*T)->droit==NULL)
        {
            free(*T);
            *T=NULL;
            return;
        }
        if((*T)->gauche==NULL)
        {
            *T=(*T)->droit;
            free(temp);
            return;
        }
        if((*T)->droit==NULL)
        {
            *T=(*T)->gauche;
            free(temp);
            return;
        }
        arbre temp1=temp;
        temp=temp->gauche;
        while(temp->droit!=NULL)
        {
            temp1=temp;
            temp=temp->droit;
        }
        (*T)->cle=temp->cle;
        temp1->droit=temp->gauche;
        free(temp);
        /*if(temp->gauche==NULL)
        {
            temp1->gauche=NULL;
            free(temp);
        }
        else
        {
            temp1->gauche=temp->gauche;
            free(temp);
        }*/
        return;
    }
    if(val>(*T)->cle)
        return suppressionAbrRecursive(val,&(*T)->droit);
    if(val<(*T)->cle)
        return suppressionAbrRecursive(val,&(*T)->gauche);
}
/*
int main()
{
    arbre D1=faireArbre(28,NULL,NULL);
    arbre D2=faireArbre(21,NULL,NULL);
    arbre D=faireArbre(25,D2,D1);
    arbre G1=faireArbre(6,NULL,NULL);
    arbre G2=faireArbre(8,G1,NULL);
    arbre G3=faireArbre(13,NULL,NULL);
    arbre G4=faireArbre(12,G2,G3);
    arbre G5=faireArbre(3,NULL,NULL);
    arbre G=faireArbre(5,G5,G4);
    arbre T=faireArbre(20,G,D);
    //affichageLargeur(T);
    //affichagePrefixe(T);
    //printf("\n\n");
    tableau L=arbreTableauInfixe(T);
    affichageTableau(L);
    insererAbrIterative(26,&T);
    tableau S=arbreTableauInfixe(T);
    affichageTableau(S);
    /*printf("%d\n\n",testAbrInfixe(T));
    arbre S=rechercheAbr(33,T);
    if(S!=NULL)
        printf("%d\n\n",S->cle);
    else
        printf("Element non trouvé\n\n");
    insererAbrIterative(14,&T);
    affichageTableau(arbreTableauInfixe(T));
    insererAbrRecursive(15,&T);
    affichageTableau(arbreTableauInfixe(T));
    insererAbrIterative(-22,&T);
    affichageTableau(arbreTableauInfixe(T));
    suppressionAbrRecursive(13,&T);
    affichageTableau(arbreTableauInfixe(T));
    suppressionAbrRecursive(26,&T);
    affichageTableau(arbreTableauInfixe(T));
    libererArbre(&T);
    //libererTableau(L);
    return 0;
}*/
