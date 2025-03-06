/*
Ex. 25
RIMBALZI PALLINA

Data una pallina che rimbalza ogni volta a
un’altezza pari all’80% della altezza
precedente, fino a quando l’altezza è maggiore
di 1 cm. Chiedere in input l’altezza X da cui
parte la pallina, quindi calcolare e stampare
tutte le altezze ed il nr totale di rimbalzi
effettuati.
*/

#include <iostream>
using namespace std;
int main()
{
    double altezza;
    cout << "Inserisci l'altezza iniziale della pallina (in cm): ";
    cin >> altezza;

    int rimbalzi = 0;
    while (altezza > 1)
    {
        altezza *= 0.8;
        rimbalzi++;
        cout << "Rimbalzo " << rimbalzi << ": " << altezza << " cm" << endl;
    }

    cout << "Numero totale di rimbalzi: " << rimbalzi << endl;
    return 0;
}