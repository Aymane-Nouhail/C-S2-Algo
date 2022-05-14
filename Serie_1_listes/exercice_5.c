#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"


liste concatenateListe(liste L1, liste L2){
    /*liste L=NULL;
    liste temp=L1;
    while(temp!=NULL){ 
        ajoutFin(temp->element,&L); 
        temp=temp->suivant;
        }*/
    liste A = cloneListe(L1);
    liste B = cloneListe(L2);
    liste temp=A;
    while(temp->suivant!=NULL) temp = temp->suivant;
    temp->suivant=B;
    return A;
}
int main(){
    liste L = saisieListe(3);
    liste T = saisieListe(2);
    liste A=concatenateListe(L,T);
    //liste clone=cloneListe(L);
    affichageListe(L);
    affichageListe(T);
    liberer(&T);
    affichageListe(A);
    return 0;
}

