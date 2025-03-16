/*
Dati in input un testo e un numero intero N minore di 26,
restituire in uscita il testo crittografato con un Codice
di Cesare che sposti ogni lettera di N lettere.
*/

#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    cout << "Il valore di N deve essere minore di 26..." << endl;
    system("PAUSE");
    cout << "Dammi il valore di N, da tastiera: " << endl;
    cin >> N;
    do
    {
        cout << "Il valore di N è MAGGIORE di 26..." << endl;
        cout << "...deve essere MINORE..." << endl;
        cout << "Riprovare: ";
        cin >> N;
    } while (N > 26);
    
    return 0;
}