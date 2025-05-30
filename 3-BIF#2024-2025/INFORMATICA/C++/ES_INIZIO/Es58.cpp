/*Ex 58M-F

VETTORE CARATTERI INVERTI

Definisci una funzione Reverse che inverte un vettore
di caratteri e lo rende al chiamante in modo dinamico

    1. Nel main,  dichiara un vettore CHAR V1[N];
    2. Stampa v1 (STAMPAVET)
    3. Carica v1 con lettere a caso (CARICAVET)

Chiama la funzione REVERSE che legge v1 e lo lascia come e', ma
restituisce  un  vettore  invertito.

Infine stampa il vettore invertito  ( STAMPAVET)
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

// Funzione per stampare il vettore void stampavett(char[], int);

// Funzione per caricare il vettore con caratteri casuali
void caricaVett(char[], int);

void stampaVett(char[], int);
char *unoReverse(char[], int);

int main()
{
    const int L = 10;
    char vett[L];

    caricaVett(vett, L);
    stampaVett(vett, L);

    system("pause");

    char *invertedVett = unoReverse(vett, L);
    stampaVett(invertedVett, L);
    delete[] invertedVett;

    system("pause");
}

void stampaVett(char vett[], int L)
{
    for (int k = 0; k < L; k++)
        cout << vett[k] << "\t";
    cout << endl;
}
void caricaVett(char vett[], int L)
{
    srand(time(NULL));
    for (int k = 0; k < L; k++)
        vett[k] = rand() % 26 + 65;
}
char *unoReverse(char vett[], int L)
{
    char *vett1 = new char[L];
    for (int i = 0; i < L; i++)
    {
        vett1[i] = vett[L - 1 - i];
    }
    return vett1;
}
