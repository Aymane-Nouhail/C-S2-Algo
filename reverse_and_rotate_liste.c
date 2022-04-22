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
liste reverse_recursion(liste L){
    if(L == NULL) return NULL;
    if (L->suivant ==  NULL){
        return L;
    }
    liste temp = reverse_recursion(L->suivant);
    L->suivant->suivant = L;
    L->suivant = NULL;
    return temp;
}

void reverse_iterative(liste *L){
    liste prev = NULL, current = *L, next = NULL;
    while(current!=NULL){
        next = current->suivant;
        current->suivant = prev;
        prev = current;
        current = next;
    }
    *L = prev;
    return;
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
    L = reverse_recursion(L); affichageListe(L);
    //reverse_affichageListe(L);
    //affichageListe(L);
    rotate(L);
    affichageListe(L);
    return 0;
}
