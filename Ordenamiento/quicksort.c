// simple C program for Quick Sort
#include <stdio.h>

// to swap two numbers
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void qs(int lista[],int limite_izq,int limite_der)
{
    int izq,der,temporal,pivote;

    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];

    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}

}

void quicksort(int lista[],int n)
{
    qs(lista,0,n-1);
}

// function to print the array
void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quicksort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
