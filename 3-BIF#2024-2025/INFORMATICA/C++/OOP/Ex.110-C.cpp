/*
Ex 110-C
Classe Contatore bolletta mensile
Modificare ex 110B aggiungendo

    1. Attributi:
        gestione conteggio scatti per i 12 mesi (decidi la variabile)
    Costo euro resta  uno solo
    2. Metodi:
        Adeguare ci coseguenza i 2  costruttori ed  i  vari metodi dove è necessario
Aggiungere i seguenti metodi:
    1. staBolAnn: stampa totale bolletta anno
    2. setEuro: imposta valore costo euro per scatto
    3. view: stampa tutto scatti dei dodici mesi e costoeuro/scatto
main():
Chiamare i vari Metodi
*/
#include <iostream>
using namespace std;
class Contatore
{
private:
    int scattiMensili[12];     // Array per memorizzare gli scatti mensili
    double costoEuroPerScatto; // Costo per scatto in euro

public:
    // Costruttore di default
    Contatore() : scattiMensili{0}, costoEuroPerScatto(0.0) {}

    // Costruttore con parametri
    Contatore(const int scatti[12], double costo) : costoEuroPerScatto(costo)
    {
        for (int i = 0; i < 12; ++i)
        {
            scattiMensili[i] = scatti[i];
        }
    }

    // Metodo per impostare il costo per scatto
    void setEuro(double costo)
    {
        costoEuroPerScatto = costo;
    }

    // Metodo per stampare la bolletta annuale
    void staBolAnn() const
    {
        int totaleScatti = 0;
        for (int i = 0; i < 12; ++i)
        {
            totaleScatti += scattiMensili[i];
        }
        double totaleCosto = totaleScatti * costoEuroPerScatto;
        std::cout << "Totale bolletta annuale: " << totaleCosto << " euro" << std::endl;
    }

    // Metodo per visualizzare i dettagli
    void view() const
    {
        std::cout << "Scatti mensili: ";
        for (int i = 0; i < 12; ++i)
        {
            std::cout << scattiMensili[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Costo per scatto: " << costoEuroPerScatto << " euro" << std::endl;
    }
};

int main()
{
    int scatti[12] = {100, 120, 110, 130, 140, 150, 160, 170, 180, 190, 200, 210};
    Contatore contatore(scatti, 0.05);

    contatore.view();        // Visualizza i dettagli iniziali
    contatore.staBolAnn();   // Stampa la bolletta annuale
    contatore.setEuro(0.06); // Imposta un nuovo costo per scatto
    contatore.view();        // Visualizza i dettagli aggiornati
    contatore.staBolAnn();   // Stampa la nuova bolletta annuale

    return 0;
}