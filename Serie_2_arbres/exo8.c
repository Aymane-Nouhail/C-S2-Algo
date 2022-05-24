#include"parcours.c"

int feuilles_profondeur(arbre T)
{
    if(T==NULL)
        return 0;
    pile_arbre P;
    P.longueur=0;
    arbre temp=T;
    empiler(T,&P);
    int count = 0;
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        //printf("%d ",temp->cle);
        if(temp->droit == NULL && temp->gauche == NULL) count++;
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return count;
}
int minimum_profondeur(arbre T)
{
    if(T==NULL)
        exit(EXIT_FAILURE);
    pile_arbre P;
    P.longueur=0;
    arbre temp=T;
    empiler(T,&P);
    int res = T->cle;
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        //printf("%d ",temp->cle);
        if(temp->cle < res) res = temp->cle;
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return res;
}

int main(){
	arbre T1=NULL;
	arbre T2=NULL;
	arbre T3=NULL;
	arbre T4=NULL;
	T4=faireArbre(15,NULL,NULL);
	T1=faireArbre(2,NULL,NULL);
	T2=faireArbre(10,NULL,NULL);
	arbre T=faireArbre(3,T1,T2);
	T3=faireArbre(10,T,T);
	printf("%d\n",feuilles_profondeur(T3));
	printf("%d\n",minimum_profondeur(T3));
	return 0;
}

