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

int arbreSomme(arbre T){
	if(T == NULL){ printf("exiting\n"); exit(EXIT_FAILURE);}
	if(T->droit == NULL && T->gauche == NULL) return T->cle;
	if(T->gauche == NULL) return T->cle + arbreSomme(T->droit);
	if(T->droit ==  NULL) return T->cle + arbreSomme(T->gauche);
	return T->cle + arbreSomme(T->gauche) + arbreSomme(T->droit) ;
}

int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(10,NULL,NULL);
    T2=faireArbre(20,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
 	printf("le min est %d , le max est %d\n",arbreMin(T),arbreMax(T));
	printf("la somme est %d\n",arbreSomme(T));
    return 0;
}

