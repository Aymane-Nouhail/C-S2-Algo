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
        for(int i=0 ; i<T.rows*T.cols ; i++){
            printf("-----------------\n");
            scanf("%lf",T.tete+i);
        }
    }
    return;
}

//print a matrix
void printMatrix(matrix T){
    if(T.tete == NULL)
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
        temp = M->tete[n+k];
        M->tete[n+k] = M->tete[m+k];
        M->tete[m+k] = temp;
    }
}
//row(i)<-row(i)-a*row(j)
void linearCombin(int i,int j,double a,matrix* M){
    int n = M->cols*j;
    int m = M->cols*i;
    for(int k=0; k<M->cols ; k++) {
        M->tete[m+k] = M->tete[m+k] + a*M->tete[n+k];
    }
}

/*void echellonner(matrix* M){
    double temp;
    int k=0;
    int n = M->cols;
    int m = M->rows;
    for(int i=0;i<m-1;i++){
        //temp=-M->tete[n*(1+i)+k]/M->tete[n*(i)+k];
        //printf("%lf",temp);
        linearCombin(i+1,i,temp,M);
        exchangeRows(i,i+1,M);
        i++;
        temp=-M->tete[n*(1+i)+k]/M->tete[n*(i)+k];
        linearCombin(i+1,i,temp,M);
        i--;
        exchangeRows(i,i+1,M);
        k++;
        temp=-M->tete[n*(i+1)+k]/M->tete[n*(i)+k];
        linearCombin(i+1,i,temp,M);
        for(int j=1;j<m-1;j++){
            exchangeRows(i+1,i,M);
            i=i+j;
            temp=-M->tete[n*(1+i)+k]/M->tete[n*(i)+k];
            linearCombin(i+1,i,temp,M);
            i=i-j;
            exchangeRows(i,i+1,M);
            k++;
        }
        printMatrix(*M);
    }
}*/

//multiply row(i) with a.
void multiplyRow(int i, double a, matrix* M){
    if(i>M->rows) return;
    int m = M->cols*i;
    for(int k=0; k<M->cols ; k++)
        M->tete[m+k] = a*M->tete[m+k];
    return;
}

//adds two matrices together, returns first matrix if addition is invalid.
matrix addition(matrix A, matrix B){
    if(A.cols!=B.cols || A.rows!=B.rows) return A;
    matrix C=createMatrix(A.cols,A.rows);
    for(int i=0;i<A.cols*A.rows;i++) C.tete[i]=A.tete[i]+B.tete[i];
    return C;
}

//returns a copy of input matrix.
matrix cloneMatrix(matrix M){
    matrix C = createMatrix(M.rows,M.cols);
    for(int i=0;i<M.cols*M.rows;i++) C.tete[i]=M.tete[i];
    return C;
}

//echelons a matrix.
void echelonner(matrix* M){
    int lead = 0, i;
    float temp;
    int rowCount = M->rows;
    int colCount = M->cols;
    for(int r=0;r<rowCount;r++){
        if(colCount<=lead) return;
        i = r;
        while(M->tete[ (i*colCount) + lead]== 0){
            i++;
            if(rowCount == i){
                i = r;
                lead++;
                if(colCount == lead) return;
                }
            }
        exchangeRows(i,r,M);
        if(M->tete[(r*colCount) + lead]!=0) multiplyRow(r,1/M->tete[ (r*colCount) + lead],M);
        for(i=0;i<rowCount;i++){
            temp=M->tete[(i*colCount) + lead];
            if(i!=r) linearCombin(i,r,-temp,M);
        }
    lead++;
    //printMatrix(*M);
    }
}

//returns rank of a matrix, prints its echelonned form, doesn't modify the input.
int rankMatrix(matrix A){
    matrix M = cloneMatrix(A);
    echelonner(&M);
    int count=0, rank=0;
    float temp;
    for(int i=0;i<M.rows;i++){
        for(int j=0;j<M.cols;j++){
            temp=M.tete[(i*M.cols)+j];
            if(temp == 0) count++;
            //printf("temp : %lf\n",temp);
            //printf("count : %d\n",count);
        }
        if(count==M.cols) rank++;
        count=0;
    }
    printMatrix(M);
    libererMatrix(&M);
    return A.rows-rank;
}

int main(){
    int a,b;
    printf("Enter the number of rows then the number of cols: ");
    scanf("%d%d",&a,&b);
    matrix M = createMatrix(a,b);
    saisieMatrix(M);
    printMatrix(M);
    //multiplyRow(5,6,&M);
    //printMatrix(M);
    //exchangeRows(0,1,&M);
    //printMatrix(M);
    //linearCombin(1,0,2,&M);
    //echelonner(&M);
    printf("%d\n",rankMatrix(M));
    printMatrix(M);
    printMatrix(addition(M,M));
    matrix C=cloneMatrix(M);
    printMatrix(C);
    //echelonner(&M);
    return 0;
}