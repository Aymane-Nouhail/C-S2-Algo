#include"parcours.c"
arbre recherche_parcours(int x, arbre T)
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
        //printf("%d ",temp->cle);
        if(x == temp->cle) return temp;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return NULL;
}

int occurence(int x, arbre T){
    if(T==NULL)
        return 0;
    file_arbre F;
    F.longueur=0;
    arbre temp=T;
    int count=0;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        //printf("%d ",temp->cle);
        if(x == temp->cle) count++;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return count;
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
	T3=faireArbre(10,T2,T4);
	printf("%p\n",recherche_parcours(10,T3));
	printf("%d\n",occurence(10,T3));
	return 0;
}
