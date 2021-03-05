#include <iostream>
using namespace std;

void seleccion(int vector[], int tam);
void burbuja(int vector[], int tam);
void insercion(int vector[], int tam);
void mergeSort(int vector[], int pinicial, int pfinal);
void merge(int vector[], int pinicial, int pfinal, int medio);
void quickSort(int vector[], int pinicial, int pfinal);
void heapSort(int vector[], int tam);
void heap(int vector[], int tam, int mid);

void seleccion(int vector[], int tam) {
    int min;
    for (int i=0; i<tam; i++) {
        min = i;
        for(int j=i+1; j<tam ; j++)
            if(vector[j] < vector[min])
                min = j;
        swap(vector[i], vector[min]);
    }
}

void burbuja(int vector[], int tam)
{
    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
            if (vector[j] < vector[i])
                swap(vector[j], vector[i]);
}

void insercion(int vector[], int tam)
{
    int pos, aux;
    for (int i = 0; i < tam; i++)
    {
        pos = i;
        aux = vector[i];
        while (pos > 0 && vector[pos - 1] > aux)
        {
            vector[pos] = vector[pos - 1];
            pos--;
        }
        vector[pos] = aux;
    }
}

void mergeSort(int vector[], int pinicial, int pfinal)
{
    int mitad;
    if (pinicial < pfinal)
    {
        mitad = (pinicial + pfinal) / 2;
        mergeSort(vector, pinicial, mitad);
        mergeSort(vector, mitad + 1, pfinal);
        merge(vector, pinicial, pfinal, mitad);
    }
}

void merge(int vector[], int pinicial, int pfinal, int medio)
{
    int temp[pfinal - pinicial + 1];
    int i = pinicial;
    int j = medio + 1;
    int k = 0;
    while (i <= medio && j <= pfinal)
    {
        if (vector[i] < vector[j])
        {
            temp[k] = vector[i];
            i++;
        }
        else
        {
            temp[k] = vector[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        temp[k] = vector[i];
        k++;
        i++;
    }
    while (j <= pfinal)
    {
        temp[k] = vector[j];
        k++;
        j++;
    }
    for (i = pinicial; i <= pfinal; i++)
        vector[i] = temp[i - pinicial];
}

void quickSort(int vector[], int pinicial, int pfinal)
{
    int i = pinicial;
    int j = pfinal;
    int piv = vector[(pinicial + pfinal) / 2];
    do {
        while (vector[i]<piv)
            i++;
        while (vector[j]>piv)
            j--;
        if (i<=j) {
            swap(vector[j], vector[i]);
            i++;
            j--;
        }
    } while (i <= j);
    if (pinicial < j)
        quickSort(vector, pinicial, j);
    if (i < pfinal)
        quickSort(vector, i, pfinal);
}

void heapSort(int vector[], int tam)
{ 
    for (int i = tam / 2 - 1; i >= 0; i--) 
        heap(vector, tam, i); 
    for (int i = tam - 1; i >= 0; i--) { 
        swap(vector[0], vector[i]); 
        heap(vector, i, 0); 
    } 
}

void heap(int vector[], int tam, int mid)
{ 
    int largest = mid;
    int l = 2 * mid + 1;
    int r = 2 * mid + 2; 
    if (l < tam && vector[l] > vector[largest]) 
        largest = l; 
    if (r < tam && vector[r] > vector[largest]) 
        largest = r; 
    if (largest != mid) { 
        swap(vector[mid], vector[largest]); 
        heap(vector, tam, largest); 
    } 
} 