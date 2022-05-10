#include "arbre.c"

int taille(arbre T){
	if(T == NULL) return 0;
	if(T->gauche == NULL && T->droit == NULL) return 1;
	if(T->gauche == NULL) return 1+taille(T->droit);
	if(T->gauche == NULL) return 1+taille(T->gauche);
	return 1+taille(T->droit)+taille(T->gauche);
}

int noeudsInternes(arbre T){
	if(T == NULL) return 0;
	if(T->gauche == NULL && T->droit == NULL) return 0;
	if(T->gauche == NULL) return 1+noeudsInternes(T->droit);
	if(T->gauche == NULL) return 1+noeudsInternes(T->gauche);
	return 1+noeudsInternes(T->droit)+noeudsInternes(T->gauche);
}

int feuilles(arbre T){
	return taille(T)-noeudsInternes(T);
}
int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(10,NULL,NULL);
    T2=faireArbre(20,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
	printf("la taille est %d\n",taille(T));
	printf("le nombre des noeuds internes est %d\n", noeudsInternes(T));
	printf("le nombre des feuilles est %d\n",feuilles(T));
    return 0;
}
