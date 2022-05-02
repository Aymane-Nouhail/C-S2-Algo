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
	if(L == NULL){printf("[ ]\n");return;}
	printf("[ ");
	while(L!= NULL){
		printf("%s %s, %d | ",L->element.nom,L->element.prenom,L->element.rdv);
		L = L->suivant;
	}
	printf("\b\b]\n");
	return;
}
void ajoutPatient(patient P, liste *L){ //AjoutDebut
	cellule* C =(cellule*)malloc(sizeof(cellule));
	C->element = P;
	C->suivant = *L;
	*L = C;
	return;
}

patient extrairePatient(liste *L){
	//particular case : only one element.
	if((*L)->suivant == NULL){
		patient res = (*L)->element;
		free(*L);
		*L = NULL;
		return res;
	}
	liste before = *L, current = (*L)->suivant, next = (*L)->suivant->suivant; //three cellules* for readability, can use only before.
	liste res_before, res, res_next; //three cellules* for readability, can use only res_before.
	int a = 0;
	//finding the result : general case.
	while(next!= NULL){
		if(current->element.rdv == 1 && next->element.rdv == 0){
			res_before = before;
			res  = current;
			res_next = next;
			a = 1; //setting a to one to register the fact that we got inside this if statement
		}
		//moving every pointer one more to the left.
		before = before->suivant; 
		current = current->suivant; 
		next = next->suivant; 
	}
	//particular case : if last element is what we want to extract.
	if(current->element.rdv == 1 || (a==0 && (*L)->element.rdv == 0)){ //that would be if the last element has rdv == 1 or if every element has rdv == 0.
		before->suivant = NULL;
		patient x = current->element;
		free(current);
		return x;
	}
	//particular case : if first element is what we want to extract.
	if((*L)->element.rdv == 1 && a==0){ //that would be if first element rdv == 1 and if every element after has rdv == 0.
		liste temp = *L; patient res = (*L)->element;
		*L = (*L)->suivant;
		free(temp);
		return res;
	}
	//general case.
	if(a==1){
		patient x = res->element;
		res_before->suivant = res_next;
		free(res);
		res = NULL;
		return x;
	}
}

int main(){
	patient A = {"lenny", "Chris",0}; patient B = {"Ayoub", "Ayoub", 0}; 
	patient C = {"Ahmed", "Ahmed", 1}; patient D = {"Aymane", "Aymane",1};
	liste L = NULL;
	ajoutPatient(A,&L); ajoutPatient(B,&L); ajoutPatient(C,&L);ajoutPatient(D,&L);
	affichagePatients(L);
	extrairePatient(&L);
	affichagePatients(L);
	extrairePatient(&L);
	affichagePatients(L);
	extrairePatient(&L);
	affichagePatients(L);
	extrairePatient(&L);
	affichagePatients(L);
	return 0;
}
