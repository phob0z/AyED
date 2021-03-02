void ordenamientoQuicksort(int vector[], int pinicial, int pfinal);
int mitad(int vector[], int pinicial, int pfinal);

void ordenamientoQuicksort(int vector[], int pinicial, int pfinal)
{
    int i = pinicial;
    int j = pfinal;
    int piv = mitad(vector, pinicial, pfinal);
    int temp;
    do {
        while (vector[i]<piv) {
            i++;
        }
        while (vector[j]>piv) {
            j--;
        }
        if (i<=j) {
            temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (pinicial < j)
        ordenamientoQuicksort(vector, pinicial, j);
    if (i < pfinal)
        ordenamientoQuicksort(vector, i, pfinal);
}

int mitad(int vector[], int pinicial, int pfinal)
{
    return vector[(pinicial + pfinal) / 2];
}