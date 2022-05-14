#include <stdio.h>
#include <stdlib.h>
struct tab
{
    unsigned taille;
    double *tete;
};
typedef struct tab tab;
///////////////////////////////////////////////////////////
tab *allouer(unsigned n)
{
    tab *t = (tab *)malloc(sizeof(tab));
    t->taille = n;
    t->tete = (double *)malloc(n * sizeof(double));
    return t;
}
///////////////////////////////////////////////////////////
void liberer(tab **t)
{
    free((*t)->tete);
    free(*t);
    *t = NULL;
}
///////////////////////////////////////////////////////////
void saisie(tab *t)
{
    printf("Entrer les elements de votre tab : \n");
    for (int i = 0; i < t->taille; i++)
    {
        printf("--------\n"); //seperate lines
        scanf("%lf", &t->tete[i]);
    }
}
///////////////////////////////////////////////////////////
void affichage(tab *t)
{
    if(t==NULL)
    {
        printf("[ ]\n");
        return;
    }
    int i, n = (*t).taille;
    printf("[");
    for (i = 0; i < n; i++)
    {
        printf("%lf, ", t->tete[i]);
    }
    printf("\b\b]\n");
}
///////////////////////////////////////////////////////////
tab *concatener(tab *t, tab *h)
{
    int i, n = t->taille, m = h->taille;
    tab *l = allouer(n + m);
    for (i = 0; i < n; i++)
        l->tete[i] = t->tete[i];
    for (i = n; i < n + m; i++)
        l->tete[i] = h->tete[i - n];
    return l;
}
///////////////////////////////////////////////////////////
tab* merge(tab* A, tab* B)
{
    int a = A->taille, b=B->taille;
    if(a == 0) return B;
    if(b == 0) return A;
    else
    {
        if(A->tete[0] < B->tete[0]) 
        {
            tab* c=allouer(1); c->tete[0] = A->tete[0];
            A->tete++; A->taille = a-1;
            return concatener(c,merge(A, B));
        }
        else
        {
            tab* c=allouer(1); c->tete[0] = B->tete[0];
            B->tete++; B->taille=b-1;
            return concatener(c,merge(A, B));
        }
    }
}
///////////////////////////////////////////////////////////
tab* MergeSort(tab* A)
{
    int n=A->taille;
    if(n<=1) return A;
    else
    {
        tab *B = (tab *)malloc(sizeof(tab));
        B->taille=n-n/2;
        B->tete=A->tete+n/2;
        tab *C = (tab *)malloc(sizeof(tab));
        C->taille=n/2;
        C->tete=A->tete;
        //A->taille=n/2;
        return merge(MergeSort(C),MergeSort(B));
    }
}

void SelectionSort(tab* A)
{
    int n=A->taille, i, j;
    for(i=0;i<n;i++)
    {
        int c=i;
        for(j=i+1;j<n;j++)
        {
            if(A->tete[c]>A->tete[j])
            {
                c=j;
            }
        }
        double temp=A->tete[i];
        A->tete[i]=A->tete[c];
        A->tete[c]=temp;
    }
}

int main()
{
    tab *t = allouer(3);
    tab *h = allouer(3);
    //(*t).tete[1]=2;
    //printf("%f",(*t).tete[0]);
    // printf("%f \n", (*t).tete[0]);
    // printf("la taille est %d \n", (*t).taille);
    //liberer(t);
    //printf("la taille est %d \n",(*t).taille);
    saisie(t);
    affichage(t);
    saisie(h);
    affichage(h);
    tab* l = concatener(t, h);
    affichage(l);
    l=MergeSort(l);
    affichage(l);
    //liberer(&l);
    //affichage(l);
    //SelectionSort(l);
    //affichage(l);
    return 0;
}