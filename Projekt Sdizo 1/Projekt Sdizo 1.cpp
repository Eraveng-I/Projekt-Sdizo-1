// Projekt Sdizo 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestyReczne.h"
#include "TestyAutomatyczne.h"
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    //Inicjalizacja klasy testuj¹cej
    TestyReczne testy;
    TestyAutomatyczne testyAutomatyczne;

    int wybor = 999;
    string tn = "n";

    cout << "SDiZO, Projekt 1, Iwan TSwigun, 259127" << endl << endl;


    //Pocz¹tkowe menu wyboru
    while (wybor != 0) 
    {
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Drzewo Czerowno-Czarne" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0)
        {
            return 0;
        }

        cout << "Automatyzowaæ test? (t/n): ";
        cin >> tn;

        switch (wybor) 
        {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Rozpoczynam test tablicy dynamicznej..." << endl;
                if (tn == "t")
                {
                    testyAutomatyczne.testTablicy();
                }
                else
                    {
                        testy.TestTablicy();
                    }

                break;

            case 2:
                cout << "Rozpoczynam test listy..." << endl;
                if (tn == "t")
                {
                    testyAutomatyczne.testListy();
                }
                else
                    {
                        testy.TestListy();
                    }
                break;

            case 3:
                cout << "Rozpoczynam test kopca binarnego..." << endl;
                if (tn == "t")
                {
                    testyAutomatyczne.testKopca();
                }
                else
                    {
                        testy.TestKopca();
                    }
                break;

            case 4:
                cout << "Rozpoczynam test drzewa..." << endl;
                if (tn == "t")
                {
                    testyAutomatyczne.testDrzewa();
                }
                else
                    {
                        testy.TestDrzewa();
                    }
                break;

        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
