#include<stdio.h>
#include<stdlib.h>

struct tab{
	unsigned taille;
	double* tete;
};

typedef struct tab tab;

/////////////////////////////////////////

tab creer(unsigned n){
	tab T;
	T.taille = n;
	T.tete = (double*)malloc(n*sizeof(double));
	return T;	
}

void liberer(tab *T){
	T->taille = 0;
	free(T->tete);
}

void saisie(tab* T){
	printf("Entrer les elements du tableau : \n");
	for(int i=0;i<T->taille;i++){
		printf("-----------------\n");
		scanf("%lf",&T->tete[i]);
		}
}


void affichage(tab T){
	if(T.taille == 0) printf("[ ]\n");
	else{
		printf("[");
		for(int i=0;i<T.taille-1;i++){
			printf("%g , ", T.tete[i]);
		}
		printf("%g]\n",T.tete[T.taille-1]);
		//printf("]\n");
	}	
}

tab concatener(tab A, tab B){
	tab T = creer(A.taille+B.taille);
	for(int i=0;i<A.taille;i++)
		T.tete[i]=A.tete[i];
	for(int i=0;i<B.taille;i++)
		T.tete[A.taille+i]=B.tete[i];
	return T;
}
/*
def selection(T):
    for i in range(len(T)):
        for j in range(len(T)):
            if T[i]<T[j]:
                T[i],T[j]=T[j],T[i]
    return T
    
def fusion(A,B):
    a=len(A)
    b=len(B)
    if a==0:
        return B
    elif b==0:
        return A
    elif A[0]<B[0]:
        return [A[0]]+fusion(A[1:a],B)
    else:
        return [B[0]]+fusion(A,B[1:b])
*/

tab fusion(tab A, tab B){
	int a = A.taille, b = B.taille;
	if(a==0) return B;
	if(b==0) return A;
	if(A.tete[0] < B.tete[0]){
		tab c = creer(1);
		c.tete[0] = A.tete[0];
		A.tete++; 
		A.taille = a-1;
		return concatener( c , fusion(A,B) );
	}
	else{
		tab c = creer(1);
		c.tete[0] = B.tete[0];
		B.tete++;
		B.taille = b-1;
		return concatener( c , fusion(A,B) );
	}
}

tab triFusion(tab A){
	int n = A.taille;
	if(n<=1) return A;
	else{
		tab B = creer(n-n/2);
		B.tete=A.tete+n/2;
		tab C=creer(n/2);
		C.tete=A.tete;
		return fusion( triFusion(C) , triFusion(B) ); 
	}
}
void selection(tab *T){
	double temp;
	for(int i = 0 ; i<T->taille ; i++){
		for(int j = 0 ; j<T->taille ; j++){
			if(T->tete[i] < T->tete[j]){
				temp = T->tete[i];
				T->tete[i] = T->tete[j];
				T->tete[j] = temp;
			}
		}
	}
}



int main(){
	tab T = creer(5);
	saisie(&T);
	affichage(T);
	//liberer(&T);
	//affichage(T);
	//tab M = concatener(T,T);
	//selection(&T);
	T=triFusion(T);
	affichage(T);
}
