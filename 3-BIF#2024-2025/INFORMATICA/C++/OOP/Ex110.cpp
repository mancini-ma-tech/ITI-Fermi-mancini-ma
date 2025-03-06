/*
Ex 110
Classe Contatore

Definire una classe contatore (intero) con

    1. Attributi:valore  contatore
    2. Metodi:  costruttore  di default, altro costruttore che imposta ad un dato valore;
    3. Set contatore: lo incrementa/decrementa di un valore;
    4. Get: restituisce il valore contatore.

Nel main
Istanziare 1 oggetto A,
stamparlo e modificarlo + volte
Idem con un oggetto B
idem con un oggetto C allocato dinamicamente
*/

#include <iostream>
using namespace std;
class Contatore
{
private:
    int valore;

public:
    // Costruttore di default
    Contatore() : valore(0) {}

    // Altro costruttore che imposta ad un dato valore
    Contatore(int v) : valore(v) {}

    // Metodo per incrementare/decrementare il contatore
    void setContatore(int v)
    {
        valore += v;
    }

    // Metodo per ottenere il valore del contatore
    int getContatore() const
    {
        return valore;
    }
};

int main()
{
    // Istanziare 1 oggetto A
    Contatore A;
    cout << "Valore iniziale di A: " << A.getContatore() << endl;
    A.setContatore(5);
    cout << "Valore di A dopo incremento di 5: " << A.getContatore() << endl;
    A.setContatore(-2);
    cout << "Valore di A dopo decremento di 2: " << A.getContatore() << endl;

    // Istanziare 1 oggetto B
    Contatore B(10);
    cout << "Valore iniziale di B: " << B.getContatore() << endl;
    B.setContatore(3);
    cout << "Valore di B dopo incremento di 3: " << B.getContatore() << endl;
    B.setContatore(-4);
    cout << "Valore di B dopo decremento di 4: " << B.getContatore() << endl;

    // Istanziare 1 oggetto C allocato dinamicamente
    Contatore *C = new Contatore(20);
    cout << "Valore iniziale di C: " << C->getContatore() << endl;
    C->setContatore(7);
    cout << "Valore di C dopo incremento di 7: " << C->getContatore() << endl;
    C->setContatore(-5);
    cout << "Valore di C dopo decremento di 5: " << C->getContatore() << endl;

    // Deallocare l'oggetto C
    delete C;

    return 0;
}