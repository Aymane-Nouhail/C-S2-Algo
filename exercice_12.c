#include<stdio.h>
#include<stdlib.h>

struct file{
	int tab[10];
	unsigned taille;
};

typedef struct file file;


file fileVide(){
	file F;
	F.taille = 0;
	for(int i=0;i<10;i++) F.tab[i] = 0;
	return F;
}

int estVide(file F){
	if(F.taille == 0) return 1;
	return 0;
}

int lire(file F){
	return F.tab[0];
}

void enfiler(int x, file* F){
	F->taille++;
	for(int i=F->taille-1;i>0;i--){
		F->tab[i] = F->tab[i-1];
	}
	F->tab[0] = x;
	return;
}

int defiler(file* F){
	int res = F->tab[F->taille-1];
	F->tab[F->taille-1]= 0;
	return res;
}

void affichageFile(file F){
	printf("[");
	for(int i=0;i<10;i++){
		printf("%d, ",F.tab[i]);
	}
	printf("\b\b]\n");
	return;
}

int main(){
	file F = fileVide(); affichageFile(F);
	enfiler(5,&F); affichageFile(F);
	enfiler(6,&F); affichageFile(F);
	defiler(&F); affichageFile(F);
	return 0;
	
}

