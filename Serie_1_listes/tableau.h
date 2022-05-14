#include<stdio.h>
#include<stdlib.h>


struct tableau
{
    unsigned taille;
    int *tete;
};
typedef struct tableau tableau;

                        /* Interface Prototypes */
tableau creer(unsigned);
void affichageTableau(tableau);
void saisieTableau(tableau);
void libererTab(tableau);
                        /* A faire */
tableau concatenerTab(tableau, tableau); /* concatenerTab de deux tableaux */
void triInsertion(tableau); /* Le tableau lui même doit être trié */
tableau triBulles(tableau); /* Le résultat du tri doit être mis dans un autre tableau */



                        /* Implementation */
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
    printf("()");
    else
    {
        unsigned n=T.taille;
        printf("(");
        for(int i=0;i<n-1;i++)
            printf("%d, ",T.tete[i]);
        printf("%d)",T.tete[n-1]);
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
        printf("Entrer les elements du tableau : \n");
        for(int i=0;i<T.taille;i++){
            printf("-----------------\n");
            scanf("%d",T.tete+i);
        }
    }
    return;
}

//La procédure libererTab
void libererTab(tableau T)
{
    if(T.tete!=NULL)
        free(T.tete);
    return;
}

// concatenerTabTab
tableau concatenerTabTab(tableau T, tableau S)
{
    tableau V=creer(T.taille+S.taille);
    int i;
    for(i=0;i<V.taille;i++)
    {
        if(i<T.taille)
            V.tete[i]=T.tete[i];
        else
            V.tete[i]=S.tete[i-T.taille];
    }
    return V;
}

/*
int main()
{
    unsigned n;
    //printf("Donner la taille du tabealu : ");
    tableau T=creer(3);
    tableau S=creer(4);
    saisieTableau(T);
    saisieTableau(S);
    tableau R=concatenerTab(T,S);
    affichageTableau(R);
    libererTab(S);
    libererTab(T);
    libererTab(R);
    return 0;
}
*/
