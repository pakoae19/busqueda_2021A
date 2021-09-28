#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CapturaDatos(int arr[10],int *N);
void Buscar (int arr[10], int pos[10], int N, int busc, int *j);

int main ()
{
    srand(time(0));
    int pos[10],N=0,busc,arr[10],j;
    
    busc=CapturaDatos (arr,&N);
    Buscar (arr,pos,N,busc,&j);
    if (pos[0]!=-1)
    {
        printf ("\nEl número %d se encuentra en la posición %d",busc,pos[0]);
        if(j>1)
        for (int i=1;i<j;i++)
        {
            printf (" y %d ",pos[i]);
        }
        printf("\n");
    }
    else
    {
        printf ("El número %d no existe dentro del arreglo\n",busc);
    }
}

int CapturaDatos (int arr[10],int *N)
{
    int busc,i;
    
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
    printf ("\nIngresa el número que desea buscar:   ");
    scanf ("%d",&busc);
    return (busc);
}

void Buscar (int arr[10], int pos[10], int N, int busc, int *j)
{
    int i;
    
    for (i=0;i<N;i++)
    {
        if (arr[i]==busc)
        {
            pos[*j]=i;
            *j=*j+1;
        }
        else
        {
            pos[*j]=-1;
        }
    }
}
