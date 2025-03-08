/*
Ex. 98F: Struct orario e contaminuti

Definisci una struct
orario con ore e
minuti.
Poi definisci una funzione contaminuti che ha come
parametri 2 variabili di tipo orario e restituisce la differenza in
minuti tra l'ora + alta e l'ora + bassa.


Nel main leggi i valori di 2 variabili (ora1 ed ora2) di
tipo orario, quindi chiama la funzione
contaminuti(ora1,ora2) e stampa il risultato ottenuto.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

struct Orario
{
    int ore;
    int minuti;
};

int contaminuti(Orario ora1, Orario ora2)
{
    int minuti1 = ora1.ore * 60 + ora1.minuti;
    int minuti2 = ora2.ore * 60 + ora2.minuti;
    return abs(minuti2 - minuti1);
}

int main()
{
    Orario ora1, ora2;
    cout << "Inserisci ora e minuti per ora1: ";
    cin >> ora1.ore >> ora1.minuti;
    cout << "Inserisci ora e minuti per ora2: ";
    cin >> ora2.ore >> ora2.minuti;

    int differenza = contaminuti(ora1, ora2);
    cout << "La differenza in minuti tra le due ore e': " << differenza << " minuti" << endl;

    return 0;
}