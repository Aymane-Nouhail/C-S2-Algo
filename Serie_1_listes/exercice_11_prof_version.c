#include<stdio.h>
#include<stdlib.h>

#define N 10;

struct pile{
	int tab[10];
	unsigned taille;
};
typedef struct pile pile;
/////////////////////////////////////////

pile pileVide(){
	pile P;
	P.taille = 0;
	return P;
}

int estVide(pile P){
	if(P.taille == 0) return 1;
	return 0;
}

int lire(pile P){
	if(P.taille>0)
		return P.tab[0];
	
}

void empiler(int x, pile *P){
	if(P->taille<N)
		{
			P->tab[P->taille]=x;
			P->taille++;
			return;
		}
		printf("Pile pleine.\n");
		return;
}

int depiler(pile *P){
	if(P->taille>0=
	{
		P->taille--;
		return;
	}
}


void affichagePile(pile P){
	printf("[");
	for(int i=0;i<10;i++){
		printf("%d, ",P.tab[i]);
	}
	printf("\b\b]\n");
	return;
}






int main()
{
	pile P = pileVide(); printf("pile vide "); affichagePile(P);
	printf("Empiler 10 "); empiler(10,&P); affichagePile(P);
	printf("Empiler 4 "); empiler(4,&P); affichagePile(P);
	printf("Empiler 9 "); empiler(9,&P); affichagePile(P);
	printf("Empiler 5 "); empiler(5,&P); affichagePile(P);
	printf("depiler %d ",depiler(&P)); affichagePile(P);
	return 0;
}
