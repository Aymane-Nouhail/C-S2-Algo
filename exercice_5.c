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
    liste L = cloneListe(L1);
    liste temp1=L;
    while(L->suivant!=NULL) L=L->suivant;
    L->suivant=L2;
    L=temp1;
    return L;
}
int main(){
    liste L = saisieListe(3);
    liste T = saisieListe(2);
    liste A=concatenateListe(L,T);
    //liste clone=cloneListe(L);
    affichageListe(L);
    affichageListe(T);
    affichageListe(A);
}

