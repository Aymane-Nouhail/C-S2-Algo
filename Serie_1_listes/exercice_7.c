//
//  pile.c
//  
//
//  Created by El Kahoui on 27/01/2021.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pile.h"

//parenthese function

int parenthese(char ch[]){
	pile P = NULL;
	int n = strlen(ch);
	for(int i=0;i<n;i++){
		if(ch[i] =='(') empiler(1,&P);
		if(ch[i] ==')'){
			if(estVide(P) == 1) return 0;
			else depiler(&P);
		}
	}
	if(estVide(P) == 1) return 1;
	liberer(P);
	return 0;
}


int parentheseCrochets(char ch[]){
	pile P = NULL;
	int n = strlen(ch);
	for(int i=0;i<n;i++){
		if(ch[i] == '(') empiler(0,&P);
		if(ch[i] == '[') empiler(1,&P);
		if(ch[i] == ')'){
			if(P->element == 1) return 0;
			else depiler(&P);
		}
		if(ch[i] == ']'){
			if(P->element == 0) return 0;
			else depiler(&P);
		}
	}
	if(estVide(P) == 1) return 1;
	liberer(P);
	return 0;
	
}


int main()
{
    printf("\nVeuillez donner une chaine de caracteres.\n\n");
    char ch[100];
    gets(ch);
    if(parentheseCrochets(ch))
        printf("parentheses bien formatees\n\n");
    else
        printf("parentheses mal formatees\n\n");
}
