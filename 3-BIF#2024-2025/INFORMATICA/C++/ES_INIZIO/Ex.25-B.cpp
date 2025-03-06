/*
Ex 25-B
RIMBALZI PALLINA

Data una pallina che rimbalza ogni volta a
un’altezza pari all’80% della altezza precedente
fino a quando l’altezza è maggiore di 1 cm.
Chiedere in input l’altezza X del primo rimbalzo
e il numero N dei rimbalzi e in base a questi
calcolare e stampare l’altezza
finale.
*/

#include <iostream>
using namespace std;
int main()
{
    double altezza;
    int numeroRimbalzi;

    cout << "Inserisci l'altezza iniziale della pallina (in cm): ";
    cin >> altezza;
    cout << "Inserisci il numero di rimbalzi: ";
    cin >> numeroRimbalzi;

    for (int i = 0; i < numeroRimbalzi && altezza > 1; i++)
    {
        altezza *= 0.8;
        cout << "Rimbalzo " << (i + 1) << ": " << altezza << " cm" << endl;
    }

    cout << "Altezza finale dopo " << numeroRimbalzi << " rimbalzi: " << altezza << " cm" << endl;
    return 0;
}