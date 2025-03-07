/*
Ex 110-B
Classe Contatore bolletta

Modificare ex 110 aggiungendo:
attributo float euro;
Metodi:
    1. Adeguare i due costruttori per il campo euro
    2. get bolletta() (restituisce val*euro)
    3. stampaBolletta() che stampa il numero di scatti e l'importo della bolletta

Main
Istanziare un oggetto a impostando diversi valori ed ogni volta stampando la bolletta che ne deriva
*/

#include <iostream>
using namespace std;

class Contatore
{
private:
    int val;
    float euro;

public:
    // Costruttore di default
    Contatore() : val(0), euro(0.0) {}

    // Costruttore con parametri
    Contatore(int v, float e) : val(v), euro(e) {}

    // Metodo per ottenere l'importo della bolletta
    float getBolletta() const
    {
        return val * euro;
    }

    // Metodo per stampare il numero di scatti e l'importo della bolletta
    void stampaBolletta() const
    {
        cout << "Numero di scatti: " << val << endl;
        cout << "Importo bolletta: " << getBolletta() << " euro" << endl;
    }

    // Metodo per impostare il valore degli scatti
    void setVal(int v)
    {
        val = v;
    }

    // Metodo per impostare il valore dell'euro per scatto
    void setEuro(float e)
    {
        euro = e;
    }
};

int main()
{
    Contatore a(100, 0.05);
    a.stampaBolletta();

    a.setVal(200);
    a.setEuro(0.10);
    a.stampaBolletta();

    return 0;
}