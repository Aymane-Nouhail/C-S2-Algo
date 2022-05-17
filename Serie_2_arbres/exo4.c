#include "arbre.h"

int arbreMin(arbre T){
	if(T == NULL){ printf("exiting\n"); exit(EXIT_FAILURE);}
	if(T->droit == NULL && T->gauche == NULL) return T->cle;
	if(T->gauche == NULL) return min(T->cle,arbreMin(T->droit));
	if(T->droit ==  NULL) return min(T->cle,arbreMin(T->gauche));
	return min( T->cle , min(arbreMin(T->gauche),arbreMin(T->droit)) );
}

int arbreMax(arbre T){
	if(T == NULL){ printf("exiting\n"); exit(EXIT_FAILURE);}
	if(T->droit == NULL && T->gauche == NULL) return T->cle;
	if(T->gauche == NULL) return max(T->cle,arbreMin(T->droit));
	if(T->droit ==  NULL) return max(T->cle,arbreMin(T->gauche));
	return max( T->cle , max(arbreMin(T->gauche),arbreMin(T->droit)) );
}
int abr(arbre T){
	if(T == NULL) return 1;
	if(T->gauche == NULL && T->droit == NULL) return 1;
	if(T->gauche == NULL){
		if(T->cle >= arbreMin(T->droit))
			return 0;
		return abr(T->droit);
	}
	if(T->droit == NULL){
		if(T->cle <= arbreMax(T->gauche))
			return 0;
		return abr(T->gauche);
	}
	return abr(T->gauche)&& abr(T->droit);
}

arbre rechercheArbre(int x,arbre T){
    if(T == NULL) return NULL;
    if(x == T->cle) return T;
    if(x>T->cle) return rechercheArbre(x,T->droit);
    if(x<T->cle) return rechercheArbre(x,T->gauche);
}

int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(10,NULL,NULL);
    T2=faireArbre(20,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
    printf("%d\n",abr(T));
    printf("%d\n",rechercheArbre(10,T));
    return 0;
}
