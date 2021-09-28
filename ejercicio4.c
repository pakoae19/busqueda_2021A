#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CapturaDatos(int arr[10][10], int *N, int*M);
void BuscarBidimensional (int arrIn[10][10], int arrFin[10], int pos[2][10], int N, int M);
int BuscarFinal (int arr[10], int N, int pos[10], int *j);

int main ()
{
    srand(time(0));
    int N=0,M=0,arrInicial[10][10],arrFinal[10],pos[2][10],pos2[10],j=0,dato;
    
    CapturaDatos (arrInicial,&N,&M);
    BuscarBidimensional (arrInicial,arrFinal,pos,N,M);
    dato=BuscarFinal(arrFinal,N,pos2,&j);
    printf ("\nEl número menor es %d y se encuentra en la posición [%d][%d]",dato,pos[0][pos2[0]],pos[1][pos2[0]]);
    if(j>1)
    for (int i=1;i<j;i++)
    {
        printf (" y [%d][%d] ",pos[0][pos2[i]],pos[1][pos2[i]]);
    }
    printf("\n");
}

void CapturaDatos (int arr[10][10], int *N, int *M)
{
    int i,j;
    
    while (*N>10 || *N<1)
    {
        printf ("Ingresa el número de renglones, max(10):   ");
        scanf ("%d",&*N);
        if (*N>10)
            printf ("(ERROR) El número ingresado es mayor a 10\n");
        if (*N<1)
            printf("(ERROR) El número ingresado es menor a 1\n");
    }
    while (*M>10 || *M<1)
    {
        printf ("Ingresa el número de columnas, max(10):   ");
        scanf ("%d",&*M);
        if (*M>10)
            printf ("(ERROR) El número ingresado es mayor a 10\n");
        if (*M<1)
            printf("(ERROR) El número ingresado es menor a 1\n");
    }
    
    for (i=0;i<*N;i++)
    {
        for (j=0;j<*M;j++)
        {
            arr[i][j]=rand () % 10;
            printf ("   %d",arr[i][j]);
        }
        printf("\n");
       
    }
}

void BuscarBidimensional (int arrIn[10][10], int arrFin[10], int pos[2][10], int N, int M)
{
    int i,j;
    
    for (i=0;i<N;i++)
    {
        arrFin[i]=10;
        for (j=0;j<M;j++)
        {
            if (arrIn[i][j]<arrFin[i])
            {
                arrFin[i]=arrIn[i][j];
                pos[0][i]=i;
                pos[1][i]=j;
            }
        }
    }
}

int BuscarFinal (int arr[10], int N, int pos[10], int *j)
{
    int i,dato=10;
    
    for (i=0;i<N;i++)
    {
        if (arr[i]<dato)
        {
            dato=arr[i];
        }
    }
    for (i=0;i<N;i++)
    {
        if (arr[i]==dato)
        {
            pos[*j]=i;
            *j=*j+1;
        }
    }
    
    return dato;
}
