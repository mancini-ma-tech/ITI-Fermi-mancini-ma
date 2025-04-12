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
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>

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
    vector<Voce> rubrica;

public:
    AGENDA()
    {
        rubrica.reserve(10);
    }

    void addVoce()
    {
        if (rubrica.size() >= 10)
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
        v.Eta = 2023 - v.Anno; // Calcolo età
        rubrica.push_back(v);
    }

    void stampa() const
    {
        for (const auto &v : rubrica)
        {
            cout << v.Cognome << " " << v.Nome << " " << v.Nfisso << " " << v.Ncell
                 << " " << v.Anno << " " << v.Eta << endl;
        }
    }

    void delVoce(const string &cognome, const string &nome)
    {
        auto it = remove_if(rubrica.begin(), rubrica.end(),
                            [&](const Voce &v)
                            { return v.Cognome == cognome && v.Nome == nome; });
        if (it != rubrica.end())
        {
            rubrica.erase(it, rubrica.end());
            cout << "Voce cancellata." << endl;
        }
        else
        {
            cout << "Voce non trovata." << endl;
        }
    }

    void ordina()
    {
        sort(rubrica.begin(), rubrica.end(), [](const Voce &a, const Voce &b)
             { return tie(a.Cognome, a.Nome) < tie(b.Cognome, b.Nome); });
        cout << "Agenda ordinata." << endl;
    }

    int staVoce(const string &cognome, const string &nome) const
    {
        for (size_t i = 0; i < rubrica.size(); ++i)
        {
            if (rubrica[i].Cognome == cognome && rubrica[i].Nome == nome)
            {
                cout << rubrica[i].Cognome << " " << rubrica[i].Nome << " " << rubrica[i].Nfisso
                     << " " << rubrica[i].Ncell << " " << rubrica[i].Anno << " " << rubrica[i].Eta << endl;
                return i;
            }
        }
        cout << "Voce non trovata." << endl;
        return -1;
    }

    double upEta(int annoCorrente)
    {
        int sommaEta = 0;
        for (auto &v : rubrica)
        {
            v.Eta = annoCorrente - v.Anno;
            sommaEta += v.Eta;
        }
        return rubrica.empty() ? 0 : static_cast<double>(sommaEta) / rubrica.size();
    }

    void Salva(const string &filename) const
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Errore nell'apertura del file." << endl;
            return;
        }
        for (const auto &v : rubrica)
        {
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
        rubrica.clear();
        Voce v;
        string line;
        while (getline(file, line))
        {
            replace(line.begin(), line.end(), ',', ' ');
            istringstream iss(line);
            iss >> v.Cognome >> v.Nome >> v.Nfisso >> v.Ncell >> v.Anno >> v.Eta;
            rubrica.push_back(v);
        }
        cout << "Agenda caricata da file." << endl;
    }
};

int main()
{
    AGENDA *agenda = new AGENDA();
    int scelta;
    do
    {
        cout << "Menu:\n"
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
            cout << "Media eta: " << fixed << setprecision(2) << mediaEta << endl;
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