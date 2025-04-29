/*C++: PROGETTO  AGENDA TELEFONICA
Definisci in C++ una classe AGENDA che gestisce una rubrica con attributi:
un vettore di struct (lungo 10) con i seguenti campi:
    - string Cognome;
    - string Nome;
    - string Nfisso;
    - string Ncell;
    - int Anno;
    - int Eta.

Vi sono i seguenti metodi (offline) oltre al costruttore:
    - addVoce                   aggiunge una voce all’agenda, leggendo i dati da tastiera
    - stampa                    stampa tutta agenda
    - delVoce                   cancella una voce dall’agenda con parametri cognome e nome
    - ordina                    ordina l’agenda per cognome-nome  in modo crescente
    - staVoce                   stampa a video la voce cercata (cognome e nome) e restituisce la sua
                                posizione (se non esiste allora -1)
    - upEta:                    aggiorna il campo età di tutte le voci in agenda, usando il parametro
                                formale anno e restituisce la media dell'età
    - Salva                     Salva agenda su file di testo csv (Backup)
    - Carica                    carica agenda file da file di testo csv (Restore)

Nel  Main, dopo avere istanziato (in modo dinamico) un oggetto A ella classe AGENDA, lanciare un menù
con le seguenti opzioni

1.    Aggiungi voce
2.    Cancella  voce
3.    Stampa voce
4.    Ordina agenda
5.    Stampa agenda
6.     Aggiorna Età
7.    Backup
8.    Restore
9.    Esci

Quindi usare le opzioni  del menu per:
    1. Caricare 5 voci e Stampare agenda;
    2. Cercare una voce, poi Cancellare tale voce;
    3. Ordinare agenda, Stampare agenda;
    4. Salvare su file, uscire da menu e da programma;
    5. Ricaricare agenda da file.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <ctime>

using namespace std;

struct Voce
{
    string Cognome; // Cognome della persona
    string Nome;    // Nome della persona
    string Nfisso;  // Numero di telefono fisso
    string Ncell;   // Numero di telefono cellulare
    int Anno;       // Anno di nascita
    int Eta;        // Età calcolata
};

// Classe AGENDA per gestire una rubrica telefonica
class AGENDA
{
private:
    Voce rubrica[10]; // Array di massimo 10 voci
    int count;        // Contatore per il numero di voci attualmente presenti

public:
    // Costruttore: inizializza il contatore a 0
    AGENDA() : count(0) {}

    // Metodo per aggiungere una voce all'agenda
    void addVoce()
    {
        if (count >= 10) // Controlla se l'agenda è piena
        {
            cout << "Rubrica piena!" << endl;
            return;
        }
        Voce v;
        // Lettura dei dati da tastiera
        cout << "Inserisci Cognome: ";
        cin >> v.Cognome;
        cout << "Inserisci Nome: ";
        cin >> v.Nome;
        cout << "Inserisci Numero Fisso: ";
        cin >> v.Nfisso;
        cout << "Inserisci Numero Cellulare: ";
        cin >> v.Ncell;
        cout << "Inserisci Anno di Nascita: ";
        cin >> v.Anno;

        // Calcolo dinamico dell'età basato sull'anno corrente
        time_t t = time(0);
        tm *now = localtime(&t);
        v.Eta = (now->tm_year + 1900) - v.Anno;

        rubrica[count++] = v; // Aggiunge la voce all'array e incrementa il contatore
    }

    // Metodo per stampare tutte le voci dell'agenda
    void stampa() const
    {
        for (int i = 0; i < count; ++i)
        {
            const Voce &v = rubrica[i];
            // Stampa i dettagli di ogni voce
            cout << v.Cognome << " " << v.Nome << " " << v.Nfisso << " " << v.Ncell
                 << " " << v.Anno << " " << v.Eta << endl;
        }
    }

    // Metodo per cancellare una voce dall'agenda dato cognome e nome
    void delVoce(const string &cognome, const string &nome)
    {
        int index = -1;
        // Cerca la voce corrispondente
        for (int i = 0; i < count; ++i)
        {
            if (rubrica[i].Cognome == cognome && rubrica[i].Nome == nome)
            {
                index = i;
                break;
            }
        }
        if (index != -1) // Se la voce è trovata
        {
            // Sposta le voci successive per riempire il "buco"
            for (int i = index; i < count - 1; ++i)
            {
                rubrica[i] = rubrica[i + 1];
            }
            --count; // Decrementa il contatore
            cout << "Voce cancellata." << endl;
        }
        else
        {
            cout << "Voce non trovata." << endl;
        }
    }

    // Metodo per ordinare l'agenda in base a cognome e nome
    void ordina()
    {
        sort(rubrica, rubrica + count, [](const Voce &a, const Voce &b)
             { return tie(a.Cognome, a.Nome) < tie(b.Cognome, b.Nome); });
        cout << "Agenda ordinata." << endl;
    }

    // Metodo per cercare una voce e restituire la posizione
    int staVoce(const string &cognome, const string &nome) const
    {
        for (int i = 0; i < count; ++i)
        {
            if (rubrica[i].Cognome == cognome && rubrica[i].Nome == nome)
            {
                const Voce &v = rubrica[i];
                // Stampa i dettagli della voce trovata
                cout << v.Cognome << " " << v.Nome << " " << v.Nfisso
                     << " " << v.Ncell << " " << v.Anno << " " << v.Eta << endl;
                return i; // Restituisce la posizione
            }
        }
        cout << "Voce non trovata." << endl;
        return -1; // Restituisce -1 se non trovata
    }

    // Metodo per aggiornare l'età di tutte le voci e calcolare la media
    double upEta(int annoCorrente)
    {
        int sommaEta = 0;
        for (int i = 0; i < count; ++i)
        {
            rubrica[i].Eta = annoCorrente - rubrica[i].Anno; // Aggiorna l'età
            sommaEta += rubrica[i].Eta;                      // Somma le età
        }
        // Restituisce la media delle età
        return count == 0 ? 0 : static_cast<double>(sommaEta) / count;
    }

    // Metodo per salvare l'agenda su un file CSV
    void Salva(const string &filename) const
    {
        ofstream file(filename);
        if (!file) // Controlla se il file è stato aperto correttamente
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        for (int i = 0; i < count; ++i)
        {
            const Voce &v = rubrica[i];
            // Scrive i dati della voce nel file separati da virgole
            file << v.Cognome << "," << v.Nome << "," << v.Nfisso << "," << v.Ncell << ","
                 << v.Anno << "," << v.Eta << endl;
        }
        cout << "Agenda salvata su file." << endl;
    }

    // Metodo per caricare l'agenda da un file CSV
    void Carica(const string &filename)
    {
        ifstream file(filename);
        if (!file) // Controlla se il file è stato aperto correttamente
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        count = 0; // Resetta il contatore
        string line;
        while (getline(file, line) && count < 10) // Legge ogni riga del file
        {
            replace(line.begin(), line.end(), ',', ' '); // Sostituisce le virgole con spazi
            istringstream iss(line);
            Voce v;
            // Legge i dati della voce
            iss >> v.Cognome >> v.Nome >> v.Nfisso >> v.Ncell >> v.Anno >> v.Eta;
            rubrica[count++] = v; // Aggiunge la voce all'agenda
        }
        cout << "Agenda caricata da file." << endl;
    }
};
