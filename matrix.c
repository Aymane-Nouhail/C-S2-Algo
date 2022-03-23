#include<stdio.h>
#include<stdlib.h>

struct matrix
{
    int rows;
    int cols;
    double *tete;
};
typedef struct matrix matrix;

//create a matrix
matrix createMatrix(int n, int m){
    matrix M;
    M.rows = n;
    M.cols = m;
    M.tete = (double*)malloc(n*m*sizeof(double));
    return M;
}

//empty a matrix
void libererMatrix(matrix *T){
    T->rows = 0;
    T->cols = 0;
    free(T->tete);
    T->tete = NULL;
}

//fill up a matrix
void saisieMatrix(matrix T)
{
    if(T.tete==NULL)
        printf("matrix vide !\n");
    else
    {
        printf("Entrer les elements du matrix : \n");
        for(int i=0;i<T.rows*T.cols;i++){
            printf("-----------------\n");
            scanf("%lf",T.tete+i);
        }
    }
    return;
}

//print a matrix
void printMatrix(matrix T){
    if(T.tete==NULL)
    printf("[ ]"); //Empty, not really a matrix even.
    else
    {
        unsigned n=T.rows*T.cols;
        printf("[[ ");
        for(int i=0 ; i<n-1 ; i++){
            printf("%lf, ",T.tete[i]);
            if((i+1)%T.cols==0) printf("\b\b ]\n[ ");
        }
        printf("%lf ]]",T.tete[n-1]);
    }
    printf("\n\n");
    return;
}

//exchange two lines in a matrix
void exchangeRows(int i,int j,matrix* M){
    int n = M->cols*i;
    int m = M->cols*j;
    double temp;
    for(int k=0; k<M->cols;k++) {
        temp=M->tete[n+k];
        M->tete[n+k]=M->tete[m+k];
        M->tete[m+k]=temp;
    }
}
//does row(i)<-row(i)-a*row(j)
void linearCombin(int i,int j,double a,matrix* M){
    int n = M->cols*j;
    int m = M->cols*i;
    double temp;
    for(int k=0; k<M->cols;k++) {
        M->tete[m+k]=M->tete[m+k]-a*M->tete[n+k];
    }
}
int main(){
    matrix M = createMatrix(2,2);
    saisieMatrix(M);
    printMatrix(M);
    exchangeRows(0,1,&M);
    printMatrix(M);
    linearCombin(1,0,2,&M);
    printMatrix(M);
    return 0;
}
