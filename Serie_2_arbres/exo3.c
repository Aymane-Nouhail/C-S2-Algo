#include "arbre.h"

int strahler(arbre T){
	if(T == NULL) return 0;
	if(strahler(T->droit) == strahler(T->gauche)) return strahler(T->droit)+1; //strahler(T->gauche)+1
	return max( strahler(T->droit) , strahler(T->gauche) );
}

int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(10,NULL,NULL);
    T2=faireArbre(20,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
	printf("le nombre de strahler est %d\n",strahler(T));
    return 0;
}
