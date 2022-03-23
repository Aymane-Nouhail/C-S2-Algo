#include<stdio.h>
#include<stdlib.h>
#include"liste_simple.h"
#include"tableau.h"

//converts tableau to liste
liste tableauListe(tableau L){
    liste T=  NULL;
    for(int i = L.taille-1 ; i>=0 ; i--) ajoutDebut(L.tete[i],&T);
    return T;
}

//converts liste to tableau
tableau listeTableau(liste L){
    int n=longueur(L);
    tableau T=creer(n);
    for(int i=0; i<n ; i++) {T.tete[i] = L->element ; L=L->suivant;}
    return T;
}
int main(){
    tableau T = creer(5);
    saisieTableau(T);
    liste L=tableauListe(T);
    affichageListe(L);
    tableau A = listeTableau(L);
    affichageTableau(A);
}