#include <iostream>
using namespace ;

int main()
{

    int anno;

    cout << "inserisci un anno " << endl;
    cin >> anno;

    if (anno / 4 == 0 && anno / 100 != 0)
    {
        cout << "L'Anno e' Bisestile" << endl;
    }
    else
    {
        cout << "L'Anno NON e' Bisestile" << endl;
    }
}