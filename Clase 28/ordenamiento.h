#include <iostream>
using namespace std;

void ordenamientoQuicksort(int vector[], int pinicial, int pfinal);

void ordenamientoQuicksort(int vector[], int pinicial, int pfinal)
{
    int i = pinicial;
    int j = pfinal;
    int piv = vector[(pinicial + pfinal) / 2];
    int temp;
    do {
        while (vector[i]<piv) {
            i++;
        }
        while (vector[j]>piv) {
            j--;
        }
        if (i<=j) {
            swap(vector[j], vector[i]);
            // temp = vector[i];
            // vector[i] = vector[j];
            // vector[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (pinicial < j)
        ordenamientoQuicksort(vector, pinicial, j);
    if (i < pfinal)
        ordenamientoQuicksort(vector, i, pfinal);
}