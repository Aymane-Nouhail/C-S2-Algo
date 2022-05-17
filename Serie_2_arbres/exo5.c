int arbreComplet(arbre T){
    if(T == NULL) return 1;
    if(T->gauche == NULL && T->droit == NULL) return 1;
    if(T->gauche == NULL || T->droit == NULL) return 0;
    return arbreComplet(T->gauche) && arbreComplet(T->droit);
}

int profondeur(arbre T){
    if(T == NULL) return 0;
    if(T->droit == NULL && T->gauche == NULL) return 1;
    if(T->droit == NULL) return 1+profondeur(T->gauche);
    if(T->gauche == NULL) return 1+profondeur(T->droit);
    return 1+max(profondeur(T->gauche),profondeur(T->droit));
}


int arbreParfait(arbre T){
    if(T == NULL) return 1;
    if(T->droit == NULL && T->gauche == NULL) return 1;
    if(arbreComplet(T) == 0) return 0;
    if(profondeur(T->droit) != profondeur(T->gauche)) return 0;
    return arbreParfait(T->gauche) && arbreParfait(T->droit);
}

int main()
{
	arbre T1=NULL;
	arbre T2=NULL;
	arbre T3=NULL;
	arbre T4=NULL;
	T4=faireArbre(15,NULL,NULL);
	T1=faireArbre(2,NULL,NULL);
	T2=faireArbre(10,NULL,NULL);
	arbre T=faireArbre(3,T1,T2);
	T3=faireArbre(7,T,T4);
	printf("%d\n",arbreParfait(T3));
	return 0;
}
