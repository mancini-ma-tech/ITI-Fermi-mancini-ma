/*
Ex. 110
Classe  Contatore

Definire una classe contatore (intero) con

Attributi:
    valore  contatore
Metodi:
    1. costruttore  di default
    2. altro costruttore che imposta ad un dato valore
Set contatore:
    lo incrementa / decrementa di un valore
Get:
    restituisce il  valore  contatore

Main()
Istanziare 1 oggetto A,
stamparlo e modificarlo + volte
Idem con un oggetto B e con un oggetto C allocato dinamicamente
*/

#include <iostream>
using namespace std;

class Contatore
{
private:
    int valore;

public:
    // Costruttore di default che inizializza il contatore a 0
    Contatore() : valore(0) {}

    // Costruttore che inizializza il contatore ad un valore specificato
    Contatore(int v) : valore(v) {}

    // Metodo per incrementare o decrementare il valore del contatore
    void setContatore(int v)
    {
        valore += v;
    }

    // Metodo per ottenere il valore corrente del contatore
    int getContatore() const
    {
        return valore;
    }
};

int main()
{
    // Valori iniziali e incrementi/decrementi predefiniti
    int valoreInizialeA = 10, incrementoA = 5;
    int valoreInizialeB = 20, incrementoB = -3;
    int valoreInizialeC = 30, incrementoC = 7;
    int valoreInizialeD = 40, incrementoD = -10;

    // Istanziare un oggetto A e impostare il valore iniziale
    Contatore A(valoreInizialeA);
    cout << "Valore iniziale di A: " << A.getContatore() << endl;
    A.setContatore(incrementoA);
    cout << "Valore di A dopo incremento/decremento: " << A.getContatore() << endl;

    // Istanziare un oggetto B e impostare il valore iniziale
    Contatore B(valoreInizialeB);
    cout << "Valore iniziale di B: " << B.getContatore() << endl;
    B.setContatore(incrementoB);
    cout << "Valore di B dopo incremento/decremento: " << B.getContatore() << endl;

    // Istanziare un oggetto C allocato dinamicamente e impostare il valore iniziale
    Contatore *C = new Contatore(valoreInizialeC);
    cout << "Valore iniziale di C: " << C->getContatore() << endl;
    C->setContatore(incrementoC);
    cout << "Valore di C dopo incremento/decremento: " << C->getContatore() << endl;

    // Deallocare l'oggetto C
    delete C;

    // Istanziare un oggetto D e impostare il valore iniziale
    Contatore D(valoreInizialeD);
    cout << "Valore iniziale di D: " << D.getContatore() << endl;
    D.setContatore(incrementoD);
    cout << "Valore di D dopo incremento/decremento: " << D.getContatore() << endl;

    return 0;
}
