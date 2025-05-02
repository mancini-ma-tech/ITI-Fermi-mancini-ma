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
    */ \
#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct Voce
{
    string Cognome;
    string Nome;
    string Nfisso;
    string Ncell;
    int Anno;
    int Eta;
};

int main()
{
    AGENDA *agenda = new AGENDA();
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Aggiungi voce\n";
        cout << "2. Cancella voce\n";
        cout << "3. Stampa voce\n";
        cout << "4. Ordina agenda\n";
        cout << "5. Stampa agenda\n";
        cout << "6. Aggiorna Età\n";
        cout << "7. Backup\n";
        cout << "8. Restore\n";
        cout << "9. Esci\n";
        cout << "Scegli un'opzione: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            agenda->addVoce();
            break;
        case 2:
        {
            string cognome, nome;
            cout << "Inserisci Cognome: ";
            cin >> cognome;
            cout << "Inserisci Nome: ";
            cin >> nome;
            agenda->delVoce(cognome, nome);
            break;
        }
        case 3:
        {
            string cognome, nome;
            cout << "Inserisci Cognome: ";
            cin >> cognome;
            cout << "Inserisci Nome: ";
            cin >> nome;
            agenda->staVoce(cognome, nome);
            break;
        }
        case 4:
            agenda->ordina();
            break;
        case 5:
            agenda->stampa();
            break;
        case 6:
        {
            int annoCorrente;
            cout << "Inserisci l'anno corrente: ";
            cin >> annoCorrente;
            double mediaEta = agenda->upEta(annoCorrente);
            cout << "Età media aggiornata: " << mediaEta << endl;
            break;
        }
        case 7:
        {
            string filename;
            cout << "Inserisci il nome del file per il backup: ";
            cin >> filename;
            agenda->Salva(filename);
            break;
        }
        case 8:
        {
            string filename;
            cout << "Inserisci il nome del file per il restore: ";
            cin >> filename;
            agenda->Carica(filename);
            break;
        }
        case 9:
            cout << "Uscita dal programma.\n";
            break;
        default:
            cout << "Opzione non valida.\n";
        }
    } while (choice != 9);

    delete agenda;
    return 0;
}

class AGENDA
{
private:
    Voce rubrica[10];
    int count;

public:
    AGENDA() : count(0) {}

    void addVoce()
    {
        if (count >= 10)
        {
            cout << "Rubrica piena!" << endl;
            return;
        }
        Voce v;
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

        time_t t = time(0);
        tm *now = localtime(&t);
        v.Eta = (now->tm_year + 1900) - v.Anno;

        rubrica[count++] = v;
    }

    void stampa() const
    {
        for (int i = 0; i < count; ++i)
        {
            const Voce &v = rubrica[i];
            cout << v.Cognome << " " << v.Nome << " " << v.Nfisso << " " << v.Ncell
                 << " " << v.Anno << " " << v.Eta << endl;
        }
    }

    void delVoce(const string &cognome, const string &nome)
    {
        int index = -1;
        for (int i = 0; i < count; ++i)
        {
            if (rubrica[i].Cognome == cognome && rubrica[i].Nome == nome)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int i = index; i < count - 1; ++i)
            {
                rubrica[i] = rubrica[i + 1];
            }
            --count;
            cout << "Voce cancellata." << endl;
        }
        else
        {
            cout << "Voce non trovata." << endl;
        }
    }

    void ordina()
    {
        for (int i = 0; i < count - 1; ++i)
        {
            for (int j = i + 1; j < count; ++j)
            {
                if (rubrica[i].Cognome > rubrica[j].Cognome ||
                    (rubrica[i].Cognome == rubrica[j].Cognome && rubrica[i].Nome > rubrica[j].Nome))
                {
                    Voce temp = rubrica[i];
                    rubrica[i] = rubrica[j];
                    rubrica[j] = temp;
                }
            }
        }
        cout << "Agenda ordinata." << endl;
    }

    int staVoce(const string &cognome, const string &nome) const
    {
        for (int i = 0; i < count; ++i)
        {
            if (rubrica[i].Cognome == cognome && rubrica[i].Nome == nome)
            {
                const Voce &v = rubrica[i];
                cout << v.Cognome << " " << v.Nome << " " << v.Nfisso
                     << " " << v.Ncell << " " << v.Anno << " " << v.Eta << endl;
                return i;
            }
        }
        cout << "Voce non trovata." << endl;
        return -1;
    }

    double upEta(int annoCorrente)
    {
        int sommaEta = 0;
        for (int i = 0; i < count; ++i)
        {
            rubrica[i].Eta = annoCorrente - rubrica[i].Anno;
            sommaEta += rubrica[i].Eta;
        }
        return count == 0 ? 0 : static_cast<double>(sommaEta) / count;
    }

    void Salva(const string &filename) const
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        for (int i = 0; i < count; ++i)
        {
            const Voce &v = rubrica[i];
            file << v.Cognome << "," << v.Nome << "," << v.Nfisso << "," << v.Ncell << ","
                 << v.Anno << "," << v.Eta << endl;
        }
        cout << "Agenda salvata su file." << endl;
    }

    void Carica(const string &filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        count = 0;
        string line;
        while (getline(file, line) && count < 10)
        {
            for (char &ch : line)
            {
                if (ch == ',')
                {
                    ch = ' ';
                }
            }
            istringstream iss(line);
            Voce v;
            iss >> v.Cognome >> v.Nome >> v.Nfisso >> v.Ncell >> v.Anno >> v.Eta;
            rubrica[count++] = v;
        }
        cout << "Agenda caricata da file." << endl;
    }
};
