/*
Ex. 93
File, conta caratteri
Scrivere un programma che conta quanti
caratteri ci sono nel file 93_ingresso.txt.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    int count = 0;
    char ch;
    ifstream file("Z://Informatica-ITI//3-BIF#2024-2025//C++//FILE//TXT//93_ingresso.txt");

    if (file.fail())
    {
        cout << "Operazione di Apertura file FALLITA" << endl;
        return 1;
    }

    while (!file.eof())
    {
        file.get(ch);
        count++;
    }

    file.close();

    cout << "Questo è il numero dei caratteri trovati: " << count << endl;
    return 0;
}