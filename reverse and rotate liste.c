#include "liste_simple.h"


//print a liste recursively
void recursive_affichageListe(liste L){
    if(L==NULL) return;
    printf("%d, ", L->element);
    recursive_affichageListe(L->suivant);
    return;
}

//reverse print a liste
void reverse_affichageListe(liste L){
    if(L == NULL) return;
    reverse_affichageListe(L->suivant);
    printf("%d, ",L->element);
    return;
}

//reverse a liste
liste reverse(liste L){
    if(L == NULL) return NULL;
    if (L->suivant ==  NULL){
        return L;
    }
    liste temp = reverse(L->suivant);
    L->suivant->suivant = L;
    L->suivant = NULL;
    return temp;
}

//rotate a liste
void rotate(liste L){
    int first = L->element;
    liste temp = L,temp1 = L->suivant;
    while(temp1!=NULL){
        temp->element = temp1->element;
        temp = temp->suivant;
        temp1 = temp1->suivant;
    }
    temp->element = first;
    return;
}
int main(){
    liste L = saisieListe(6);
    affichageListe(L);
    L = reverse(L); affichageListe(L);
    //reverse_affichageListe(L);
    //affichageListe(L);
    rotate(L);
    affichageListe(L);
    return 0;
}
