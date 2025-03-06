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
    int valoreIniziale, incremento;

    // Istanziare un oggetto A e impostare il valore iniziale
    cout << "Inserisci il valore iniziale per A: ";
    cin >> valoreIniziale;
    Contatore A(valoreIniziale);
    cout << "Valore iniziale di A: " << A.getContatore() << endl;
    cout << "Inserisci il valore di incremento/decremento per A: ";
    cin >> incremento;
    A.setContatore(incremento);
    cout << "Valore di A dopo incremento/decremento: " << A.getContatore() << endl;

    // Istanziare un oggetto B e impostare il valore iniziale
    cout << "Inserisci il valore iniziale per B: ";
    cin >> valoreIniziale;
    Contatore B(valoreIniziale);
    cout << "Valore iniziale di B: " << B.getContatore() << endl;
    cout << "Inserisci il valore di incremento/decremento per B: ";
    cin >> incremento;
    B.setContatore(incremento);
    cout << "Valore di B dopo incremento/decremento: " << B.getContatore() << endl;

    // Istanziare un oggetto C allocato dinamicamente e impostare il valore iniziale
    cout << "Inserisci il valore iniziale per C: ";
    cin >> valoreIniziale;
    Contatore *C = new Contatore(valoreIniziale);
    cout << "Valore iniziale di C: " << C->getContatore() << endl;
    cout << "Inserisci il valore di incremento/decremento per C: ";
    cin >> incremento;
    C->setContatore(incremento);
    cout << "Valore di C dopo incremento/decremento: " << C->getContatore() << endl;

    // Deallocare l'oggetto C
    delete C;

    // Istanziare un oggetto D e impostare il valore iniziale
    cout << "Inserisci il valore iniziale per D: ";
    cin >> valoreIniziale;
    Contatore D(valoreIniziale);
    cout << "Valore iniziale di D: " << D.getContatore() << endl;
    cout << "Inserisci il valore di incremento/decremento per D: ";
    cin >> incremento;
    D.setContatore(incremento);
    cout << "Valore di D dopo incremento/decremento: " << D.getContatore() << endl;

    return 0;
}