#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CapturaDatos(int arr[10],int *N);
int Buscar (int arr[10],int pos[10], int N, int *j);

int main ()
{
    srand(time(0));
    int N=0,arr[10],pos[10],dato,j=0;
    
    CapturaDatos (arr,&N);
    dato=Buscar (arr,pos,N,&j);
    printf ("\nEl número mayor es %d y se encuentra en la posición %d",dato,pos[0]);
    if(j>1)
    for (int i=1;i<j;i++)
    {
        printf (" y %d ",pos[i]);
    }
    printf("\n");
}

void CapturaDatos (int arr[10],int *N)
{
    int i;
    
    while (*N>10 || *N<1)
    {
        printf ("Ingresa N, max(10):   ");
        scanf ("%d",&*N);
        if (*N>10)
            printf ("(ERROR) El número ingresado es mayor a 10\n");
        if (*N<1)
            printf("(ERROR) El número ingresado es menor a 1\n");
    }
    
    for (i=0;i<*N;i++)
    {
        arr[i]=rand () % 10;
        printf ("   %d",arr[i]);
    }
}

int Buscar (int arr[10], int pos[10], int N, int *j)
{
    int i,dato=0;
    
    for (i=0;i<N;i++)
    {
        if (arr[i]>=dato)
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
