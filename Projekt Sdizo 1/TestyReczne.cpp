#include "TestyReczne.h"
#include "Tablica.h"
#include "Czas.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"
//#include <iomanip>//chyba chwilowo, akcja ma byc w funkcji
#include <windows.h>//chwilowo, akcja ma byc w funkcji

using namespace std;

void TestyReczne::TestTablicy()
{
    Czas czas;
    Tablica tablica;
    int wybor = 999;
    int wartosc;
    int pozycja;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcj� tablicy:" << endl;
        cout << "    1. Dodaj na pocz�tek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usu� pierwszy" << endl;
        cout << "    5. Usu� ostatni" << endl;
        cout << "    6. Usu� kt�rykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablic�" << endl;
        cout << "    0. Wyj�cie" << endl << endl;
        cout << "Wyb�r: ";
        cin >> wybor;

        switch (wybor) {
        default:
            cout << "B��dny wyb�r!" << endl;
            break;

        case 0:
            break;

        case 1:
            cout << "Podaj warto��: ";
            cin >> wartosc;
            czas.czasStart();
            tablica.dodajNaPoczatek(wartosc);
            //Sleep(1000);//chwilowo, akcja ma byc w funkcji
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " <<  (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;
                
        case 2:
            cout << "Podaj warto��: ";
            cin >> wartosc;
            czas.czasStart();
            tablica.dodajNaKoniec(wartosc);
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;
                
        case 3:
            cout << "Podaj warto��: ";
            cin >> wartosc;
            cout << "Podaj pozycj�: ";
            cin >> pozycja;
            czas.czasStart();
            tablica.dodajGdziekolwiek(wartosc, pozycja);
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;

        case 4:
            czas.czasStart();
            tablica.usunPierwszy();
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;

        case 5:
            czas.czasStart();
            tablica.usunOstatni();
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;

        case 6:
            cout << "Podaj pozycj�: ";
            cin >> pozycja;
            czas.czasStart();
            tablica.usunKtorys(pozycja);
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;

        case 7:
            cout << "Podaj warto��: ";
            cin >> wartosc;
            czas.czasStart();
            tablica.sprawdzCzyIstnieje(wartosc);
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;

        case 8:
            czas.czasStart();
            tablica.wydrukujTablice();
            czas.czasStop();
            cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
            break;
        }
    }
}

void TestyReczne::TestListy() 
{
    Czas czas;
    Lista lista;
    int wybor = 999;
    int wartosc;
    int pozycja;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcj� listy:" << endl;
        cout << "    1. Dodaj na pocz�tek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usu� pierwszy" << endl;
        cout << "    5. Usu� ostatni" << endl;
        cout << "    6. Usu� kt�rykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj list�" << endl;
        cout << "    0. Wyj�cie" << endl << endl;
        cout << "Wyb�r: ";
        cin >> wybor;
        switch (wybor) 
        {
            default:
                cout << "B��dny wyb�r!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodajNaPoczatek(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 2:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodajNaKoniec(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 3:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                cout << "Podaj pozycj�: ";
                cin >> pozycja;
                czas.czasStart();
                lista.dodajGdziekolwiek(wartosc, pozycja);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 4:
                czas.czasStart();
                lista.usunPierwszy();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 5:
                czas.czasStart();
                lista.usunOstatni();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 6:
                cout << "Podaj pozycj�: ";
                cin >> pozycja;
                czas.czasStart();
                lista.usunKtorys(pozycja);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 7:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                lista.sprawdzCzyIstnieje(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 8:
                czas.czasStart();
                lista.wydrukujListe();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;
        }
    }
}

void TestyReczne::TestKopca() 
{
    Czas czas;
    Kopiec kopiec;
    int wybor = 999;
    int wartosc;
    while (wybor != 0) 
    {
        cout << "Wybierz funkcj� Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usu� szczyt kopca" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyj�cie" << endl << endl;
        cout << "Wyb�r: ";
        cin >> wybor;
        switch (wybor) 
        {
            default:
                cout << "B��dny wyb�r!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                kopiec.dodaj(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 2:
                czas.czasStart();
                kopiec.usunSzczyt();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 3:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                kopiec.sprawdzCzyIstnieje(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break; 

            case 4:
                czas.czasStart();
                kopiec.wydrukujKopiec();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;
        }
    }
}

void TestyReczne::TestDrzewa() 
{
    Czas czas;
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    while (wybor != 0) 
    {
        cout << "Wybierz funkcj� Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usu�" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyj�cie" << endl << endl;
        cout << "Wyb�r: ";
        cin >> wybor;
        
        switch (wybor) 
        {
            default:
                cout << "B��dny wyb�r!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.dodaj(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 2:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.usun(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 3:
                cout << "Podaj warto��: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.sprawdzCzyIstnieje(wartosc);
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;

            case 4:
                czas.czasStart();
                drzewo.wydrukujDrzewo();
                czas.czasStop();
                cout << "Operacja zaj�a Time [ms] = " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                break;
        }
    }
}