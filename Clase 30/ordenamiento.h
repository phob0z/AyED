#include <iostream>
using namespace std;

void heapSort(int vector[], int tam);
void heap(int vector[], int tam, int mid);

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