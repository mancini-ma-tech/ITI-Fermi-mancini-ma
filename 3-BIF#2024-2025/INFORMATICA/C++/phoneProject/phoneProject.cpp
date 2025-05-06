/*

C++: PROGETTO  AGENDA TELEFONICA

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
                                posizione (se non esiste allora -1);
    - upEta:                    aggiorna il campo età di tutte le voci in agenda, usando il parametro
                                formale anno e restituisce la media dell'età;
    - Salva                     Salva agenda su file di testo csv (Backup);
    - Carica                    carica agenda file da file di testo csv (Restore);

Nel  Main, dopo avere istanziato (in modo dinamico) un oggetto A della classe AGENDA, lanciare un menù
con le seguenti opzioni

1.    Aggiungi voce
2.    Cancella  voce
3.    Stampa voce
4.    Ordina agenda
5.    Stampa intera agenda
6.    Aggiorna Età
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

class AGENDA
{
private:
    Voce voci[10];
    int count;

public:
    AGENDA() : count(0) {}

    void addVoce()
    {
        if (count >= 10)
        {
            cout << "Agenda piena!" << endl;
            return;
        }
        cout << "Inserisci Cognome: ";
        cin >> voci[count].Cognome;
        cout << "Inserisci Nome: ";
        cin >> voci[count].Nome;
        cout << "Inserisci Numero Fisso: ";
        cin >> voci[count].Nfisso;
        cout << "Inserisci Numero Cellulare: ";
        cin >> voci[count].Ncell;
        cout << "Inserisci Anno di Nascita: ";
        cin >> voci[count].Anno;
        time_t t = time(0);
        tm *now = localtime(&t);
        voci[count].Eta = now->tm_year + 1900 - voci[count].Anno;
        count++;
    }

    void stampa() const
    {
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << voci[i].Cognome << " " << voci[i].Nome
                 << ", Fisso: " << voci[i].Nfisso
                 << ", Cell: " << voci[i].Ncell
                 << ", Anno: " << voci[i].Anno
                 << ", Eta: " << voci[i].Eta << endl;
        }
        system("PAUSE");
    }

    void delVoce(const string &cognome, const string &nome)
    {
        for (int i = 0; i < count; i++)
        {
            if (voci[i].Cognome == cognome && voci[i].Nome == nome)
            {
                for (int j = i; j < count - 1; j++)
                {
                    voci[j] = voci[j + 1];
                }
                count--;
                cout << "Voce eliminata." << endl;
                return;
            }
        }
        cout << "Voce non trovata." << endl;
    }

    void ordina()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (voci[i].Cognome > voci[j].Cognome ||
                    (voci[i].Cognome == voci[j].Cognome && voci[i].Nome > voci[j].Nome))
                {
                    swap(voci[i], voci[j]);
                }
            }
        }
        cout << "Agenda ordinata." << endl;
    }

    int staVoce(const string &cognome, const string &nome) const
    {
        for (int i = 0; i < count; i++)
        {
            if (voci[i].Cognome == cognome && voci[i].Nome == nome)
            {
                cout << "Voce trovata: " << voci[i].Cognome << " " << voci[i].Nome
                     << ", Fisso: " << voci[i].Nfisso
                     << ", Cell: " << voci[i].Ncell
                     << ", Anno: " << voci[i].Anno
                     << ", Eta: " << voci[i].Eta << endl;
                return i;
            }
        }
        cout << "Voce non trovata." << endl;
        return -1;
    }

    double upEta(int annoCorrente)
    {
        double sommaEta = 0;
        for (int i = 0; i < count; i++)
        {
            voci[i].Eta = annoCorrente - voci[i].Anno;
            sommaEta += voci[i].Eta;
        }
        return count > 0 ? sommaEta / count : 0;
    }

    void Salva(const string &filename) const
    {
        if (filename.empty())
        {
            cout << "Nome file non valido." << endl;
            return;
        }
        ofstream file(filename);
        if (!file)
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        for (int i = 0; i < count; i++)
        {
            file << voci[i].Cognome << "," << voci[i].Nome << ","
                 << voci[i].Nfisso << "," << voci[i].Ncell << ","
                 << voci[i].Anno << "," << voci[i].Eta << endl;
        }
        file.close();
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
            stringstream ss(line);
            getline(ss, voci[count].Cognome, ',');
            getline(ss, voci[count].Nome, ',');
            getline(ss, voci[count].Nfisso, ',');
            getline(ss, voci[count].Ncell, ',');
            ss >> voci[count].Anno;
            ss.ignore();
            ss >> voci[count].Eta;
            count++;
        }
        file.close();
        cout << "Agenda caricata da file." << endl;
    }
};

int main()
{
    AGENDA *agenda = new AGENDA();
    int scelta;
    do
    {
        cout << "\nMenu:\n"
             << "1. Aggiungi voce\n"
             << "2. Cancella voce\n"
             << "3. Stampa voce\n"
             << "4. Ordina agenda\n"
             << "5. Stampa agenda\n"
             << "6. Aggiorna Eta\n"
             << "7. Backup\n"
             << "8. Restore\n"
             << "9. Esci\n"
             << "Scelta: ";
        cin >> scelta;

        switch (scelta)
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
            cout << "Inserisci anno corrente: ";
            cin >> annoCorrente;
            double mediaEta = agenda->upEta(annoCorrente);
            cout << "Eta media aggiornata: " << mediaEta << endl;
            break;
        }
        case 7:
        {
            string filename;
            cout << "Inserisci nome file per il backup: ";
            cin >> filename;
            agenda->Salva(filename);
            break;
        }
        case 8:
        {
            string filename;
            cout << "Inserisci nome file per il restore: ";
            cin >> filename;
            agenda->Carica(filename);
            break;
        }
        case 9:
            cout << "Uscita dal programma." << endl;
            break;
        default:
            cout << "Scelta non valida." << endl;
        }
    } while (scelta != 9);

    delete agenda;
    return 0;
}