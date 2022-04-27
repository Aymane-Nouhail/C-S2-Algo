#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct patient{
	char nom[10];
	char prenom[10];
	int rdv;
};
typedef struct patient patient;

struct cellule{
	patient element;
	struct cellule * suivant;
};
typedef struct cellule cellule;
typedef struct cellule* liste;

void affichagePatients(liste L){
	printf("[ ");
	while(L!= NULL){
		printf("%s %s, %d | ",L->element.nom,L->element.prenom,L->element.rdv);
		L = L->suivant;
	}
	printf("\b\b]\n");
	return;
}
void ajoutPatient(patient P, liste *L){
	cellule* C =(cellule*)malloc(sizeof(cellule));
	C->element = P;
	C->suivant = *L;
	*L = C;
	return;
}

patient extrairePatient(liste *L){
	liste temp2 = *L; temp1 = *L, temp = *L; patient res; int a=0;
	while(temp!= NULL){
		if(temp1->element.rdv == 1 && temp->element.rdv == 0){
			res  = temp1;
			a=1;
		}
		temp2 = temp;
		temp1 = temp;
		temp = temp->suivant;
	}
	if(a==1){
		int x = res->element;
		free(res);
		es = NULL;
		return x;
	}
	return temp1->element;
}

int main(){
	patient P = {"lenny", "Chris",0};
	patient K = {"Ayoub", "Ayoub", 1};
	patient Q = {"Ahmed", "Ahmed", 1};
	liste L = NULL;
	ajoutPatient(P,&L); ajoutPatient(K,&L); ajoutPatient(Q,&L);
	affichagePatients(L);
	patient res = extrairePatient(&L);
	printf("%s\n",res.nom);
	return 0;
}
