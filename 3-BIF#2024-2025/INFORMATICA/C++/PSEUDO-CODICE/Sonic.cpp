#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using cin;
using cout;
using endl;
using namespace std;
void startGame()
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }
    int score = 0;
    int level = 1;
    char input;

    while (true)
    {
        cout << "Livello " << level << ": Premi 'a' per saltare, 'd' per scivolare, 'q' per uscire: ";
        cin >> input;
        if (cin.eof())
        {
            cout << "Input terminato. Uscita dal gioco." << endl;
            break;
        }
        if (cin.fail() || (input != 'a' && input != 'd' && input != 'q'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Comando non riconosciuto. Riprova." << endl;
            continue;
        }

        if (input == 'q')
        {
            cout << "Hai scelto di uscire. Punteggio finale: " << score << endl;
            break;
        }
        else if (input == 'a' || input == 'd')
        {
            int event = rand() % 2; // 0 for obstacle, 1 for ring
            if (event == 0)
            {
                if (input == 'a')
                {
                    cout << "Hai saltato un ostacolo!" << endl;
                    score += 10;
                }
                else
                {
                    cout << "Hai colpito un ostacolo!" << endl;
                    score -= 5;
                }
            }
            else
            {
                if (input == 'd')
                {
                    cout << "Hai raccolto un anello!" << endl;
                    score += 20;
                }
                else
                {
                    cout << "Hai perso un anello!" << endl;
                    score -= 10;
                }
            }
            level++;
            if (level > 10) // Exit condition for the loop
            {
                cout << "Hai completato tutti i livelli! Punteggio finale: " << score << endl;
                break;
            }
        }
        else
        {
            cout << "Comando non riconosciuto. Riprova." << endl;
        }
    }
}

int main()
{
    cout << "Benvenuto nel gioco in stile Sonic!" << endl;
    cout << " Premi 'a' per saltare, 'd' per scivolare, 'q' per uscire." << endl;

    char input;
    while (true)
    {
        cout << "Vuoi iniziare una nuova partita? (s/n): ";
        cin >> input;

        if (cin.eof())
        {
            cout << "Input terminato. Uscita dal gioco." << endl;
            break;
        }
        if (cin.fail() || (input != 's' && input != 'S' && input != 'n' && input != 'N'))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Comando non riconosciuto. Riprova." << endl;
            continue;
        }

        if (input == 'n' || input == 'N')
        {
            cout << "Arrivederci!" << endl;
            break;
        }
        else if (input == 's' || input == 'S')
        {
            startGame(); // Start the detailed game
        }
    }

    return 0;
}