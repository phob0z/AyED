#include <iostream>
using namespace std;

int main() {
    cout << "Se considera 0 como par\n";
    //Sacando el modulo
    for (int i=0; i<=100; i++)
        if (i%2==0)
            cout << i << endl;
/*
    //Con paso 2
    for (int i=0; i<=100; i=i+2)
        cout << i << endl;
    return 0;
*/
}