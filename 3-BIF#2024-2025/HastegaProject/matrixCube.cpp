/*
Data una matrice di interi 5 x 5 è riempita
con numeri a caso tra 0 e 3, che simula il
layout di un magazzino di cubi.
Il numero presente in una cella esprime quanti
cubi sono posizionati sulla cella stessa (uno sopra l'altro)
es. 0 : nessun cubo, 2 due cubi...
Calcolare quante facce libere di cubi ci sono
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 5;

int main()
{
    int warehouse[SIZE][SIZE];
    srand(time(0));

    // Fill the matrix with random numbers between 0 and 3
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            warehouse[i][j] = rand() % 4;
        }
    }

    // Display the matrix
    cout << "Warehouse layout:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << warehouse[i][j] << " ";
        }
        cout << "\n";
    }

    int freeFaces = 0;

    // Calculate free faces
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int cubes = warehouse[i][j];
            if (cubes > 0)
            {
                // Top face
                freeFaces += 1;

                // Bottom face
                freeFaces += 1;

                // Left face
                if (j == 0 || warehouse[i][j - 1] < cubes)
                {
                    freeFaces += cubes - (j > 0 ? warehouse[i][j - 1] : 0);
                }

                // Right face
                if (j == SIZE - 1 || warehouse[i][j + 1] < cubes)
                {
                    freeFaces += cubes - (j < SIZE - 1 ? warehouse[i][j + 1] : 0);
                }

                // Front face
                if (i == 0 || warehouse[i - 1][j] < cubes)
                {
                    freeFaces += cubes - (i > 0 ? warehouse[i - 1][j] : 0);
                }

                // Back face
                if (i == SIZE - 1 || warehouse[i + 1][j] < cubes)
                {
                    freeFaces += cubes - (i < SIZE - 1 ? warehouse[i + 1][j] : 0);
                }
            }
        }
    }

    cout << "Total free faces: " << freeFaces << "\n";

    return 0;
}
