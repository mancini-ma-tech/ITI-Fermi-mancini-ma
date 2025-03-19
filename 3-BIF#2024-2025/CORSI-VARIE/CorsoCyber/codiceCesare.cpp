/*
Dati in input un testo e un numero intero n minore di 26,
restituire in uscita il testo crittografato con un Codice
di Cesare che sposti ogni lettera di n lettere.
*/

#include <iostream>
#include <string>
using namespace std;
// Funzione che applica il Codice di Cesare al testo dato con uno spostamento specificato
string caesarCipher(const string &text, int shift)
{
	string result = "";
	shift = shift % 26; // Assicura che lo spostamento sia nell'intervallo 0-25

	// Itera su ogni carattere del testo
	for (char c : text)
	{
		if (isalpha(c))
		{										// Controlla se il carattere è una lettera
			char base = islower(c) ? 'a' : 'A'; // Determina la base (a o A) in base al caso
			c = (c - base + shift) % 26 + base; // Applica lo spostamento e mantiene il caso originale
		}
		result += c; // Aggiunge il carattere (modificato o no) al risultato
	}

	return result; // Restituisce il testo crittografato
}

int main()
{
	string text;
	int n;

	// Richiede all'utente di inserire il testo da crittografare
	cout << "Enter text: ";
	getline(cin, text);
	// Richiede all'utente di inserire lo spostamento
	cout << "Enter shift (n < 26): ";
	cin >> n;

	// Crittografa il testo usando il Codice di Cesare
	string encryptedText = caesarCipher(text, n);
	// Stampa il testo crittografato
	cout << "Encrypted text: " << encryptedText << endl;

	return 0; // Termina il programma
}