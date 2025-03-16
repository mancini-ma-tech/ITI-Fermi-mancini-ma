/*
Dati in input un testo e un numero intero N minore di 26,
restituire in uscita il testo crittografato con un Codice
di Cesare che sposti ogni lettera di N lettere.
*/

#include <iostream>
#include <string>
using namespace std;

// Funzione per crittografare il testo usando il Codice di Cesare
string caesarCipher(string text, int shift)
{
    string result = "";
    // Itera su ogni carattere del testo
    for (int i = 0; i < text.length(); i++)
    {
        // Controlla se il carattere è una lettera
        if (isalpha(text[i]))
        {
            // Determina
            {
                result += text[i];
            }
        }
        return result;
    }

    int main()
    {
        int N = 0;
        cout << "Il valore di N deve essere minore di 26..." << endl;
        cout << "Dammi il valore di N, da tastiera: " << endl;
        cin >> N;
        while (N >= 26)
        {
            cout << "Il valore di N è MAGGIORE o UGUALE a 26..." << endl;
            cout << "...deve essere MINORE..." << endl;
            cout << "Riprovare: ";
            cin >> N;
        }

        cin.ignore(); // to ignore the newline character left in the buffer
        string text;
        cout << "Inserisci il testo da crittografare: ";
        getline(cin, text);

        string encryptedText = caesarCipher(text, N);
        cout << "Testo crittografato: " << encryptedText << endl;

        return 0;
    }