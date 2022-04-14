#include<stdio.h>
#include<stdlib.h>

struct group
{
    int id;
    int size;
};

typedef struct group group;


struct cellule
{
	group element;
    struct cellule * suivant;
};
typedef struct cellule cellule;
typedef struct cellule* file;




// Affichage d'une file
void affichageFile(file L)
{
    if(L==NULL)
        printf("[ ]\n");
    else
    {
        printf("[");
        file temp=L;
        while(temp->suivant!=NULL)
        {
            printf("(%d, %d ) , ",temp->element.id, temp->element.size);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("(%d, %d)",temp->element.id,temp->element.size);
        printf("]\n");
    }
}

void enfilerGroup(group G,file * F)
{
	if((*F) == NULL){
		cellule * C=(cellule *)malloc(sizeof(cellule));
    	C->element=G;
    	C->suivant=NULL;
    	*F = C;
    	return;
	}
	file temp = *F, temp1 = *F;
	while(temp!=NULL){
		if(temp->element.id == G.id) 
		{
			temp->element.size += G.size;
			return;
		}
		temp1 = temp;
		temp = temp->suivant;
	}	
    cellule * C=(cellule *)malloc(sizeof(cellule));
    C->element=G;
    C->suivant=NULL;
    temp1->suivant = C;
    return;
}

int main(){
	file F = NULL;
	affichageFile(F);
	group G1 = {0,5},G2 = {0,2},G3 = {2,3};
	enfilerGroup(G1,&F);
	enfilerGroup(G2,&F);
	enfilerGroup(G3,&F);
	affichageFile(F);
	return 0;
}

