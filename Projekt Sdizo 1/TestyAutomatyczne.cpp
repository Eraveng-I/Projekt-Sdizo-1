#include "TestyAutomatyczne.h"
#include <iostream>
#include <fstream>
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

using namespace std;

void TestyAutomatyczne::testTablicy() 
{
    srand(time(NULL));
    Czas czas;
    Tablica tablica;
    int wybor = 999;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcjê tablicy:" << endl;
        cout << "    1. Dodaj na pocz¹tek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuñ pierwszy" << endl;
        cout << "    5. Usuñ ostatni" << endl;
        cout << "    6. Usuñ którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicê" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0)
        {
            return;
        }

        cout << "Plik zawieraj¹cy dane wejœciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        //plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        //plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/Tablica/" + daneWyjsciowe, fstream::out);

        plikWejsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Input/" + daneWejsciowe, fstream::in);
        plikWyjsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Output/Tablica/" + daneWyjsciowe, fstream::out);

        //Sprawd¿ czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
                return;
            }

        if (plikWyjsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
                return;
            }

        switch (wybor) 
        {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.dodajNaPoczatek(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.dodajNaKoniec(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.dodajGdziekolwiek(wartosc, rand() % tablica.rozmiarTablicy);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                cout << "Rozpoczynam test automatyczny...";

                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.usunPierwszy();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.usunOstatni();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }
                while (tablica.rozmiarTablicy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.usunKtorys(rand() % tablica.rozmiarTablicy);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    //plikWyjsciowy << czas.czasWykonania() << endl;
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl; 
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    tablica.dodajNaPoczatek(wartosc);
                }

                for (int i = 0; i < tablica.rozmiarTablicy; i++) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    tablica.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.czasStart();
                tablica.wydrukujTablice();
                czas.czasStop();
                cout << "Czas wykonania: " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << "ms" << endl;
                break;
        }
    }
}

void TestyAutomatyczne::testListy() 
{
    srand(time(NULL));
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcjê listy:" << endl;
        cout << "    1. Dodaj na pocz¹tek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuñ pierwszy" << endl;
        cout << "    5. Usuñ ostatni" << endl;
        cout << "    6. Usuñ którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listê" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0)
        {
            return;
        }

        cout << "Plik zawieraj¹cy dane wejœciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki        
        plikWejsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Input/" + daneWejsciowe, fstream::in);
        plikWyjsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Output/Lista/" + daneWyjsciowe, fstream::out);
        
        //Sprawd¿ czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
                return;
            }

        if (plikWyjsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
                return;
            }

        switch (wybor) 
        {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.dodajNaPoczatek(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.dodajNaKoniec(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;

                    if (lista.rozmiarListy == 0) 
                    {
                        czas.czasStart();
                        lista.dodajGdziekolwiek(wartosc, 0);
                        czas.czasStop();
                    }
                    else 
                        {
                            czas.czasStart();
                            lista.dodajGdziekolwiek(wartosc, 1);
                            czas.czasStop();
                        }
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiarListy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.usunPierwszy();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 5:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiarListy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.usunOstatni();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 6:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }
                while (lista.rozmiarListy != 0) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.usunKtorys(rand() % lista.rozmiarListy);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 7:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    lista.dodajNaPoczatek(wartosc);
                }

                for (int i = 0; i < lista.rozmiarListy; i++) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    lista.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 8:
                czas.czasStart();
                lista.wydrukujListe();
                czas.czasStop();
                cout << "Czas wykonania: " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << "ms" << endl;
                break;
        }
    }
}

void TestyAutomatyczne::testKopca() 
{
    srand(time(NULL));
    Czas czas;
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcjê Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuñ szczyt kopca" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0)
        {
            return;
        }

        cout << "Plik zawieraj¹cy dane wejœciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Input/" + daneWejsciowe, fstream::in);
        plikWyjsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Output/Kopiec/" + daneWyjsciowe, fstream::out);

        
        //Sprawd¿ czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
                return;
            }

        if (plikWyjsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
                return;
            }

        switch (wybor) 
        {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    kopiec.dodaj(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:


                while (plikWejsciowy.good()) 
                {
                    //plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    kopiec.usunSzczyt();
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    kopiec.dodaj(wartosc);
                }

                for (int i = 0; i < kopiec.rozmiarKopca; i++) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    kopiec.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 4:
                czas.czasStart();
                kopiec.wydrukujKopiec();
                czas.czasStop();
                cout << "Czas wykonania: " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << "ms" << endl;
                break;
        }
    }
}

void TestyAutomatyczne::testDrzewa() 
{
    srand(time(NULL));
    Czas czas;
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) 
    {
        cout << "Wybierz funkcjê Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuñ" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjœcie" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;

        //Zamknij, je¿eli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawieraj¹cy dane wejœciowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Input/" + daneWejsciowe, fstream::in);
        plikWyjsciowy.open("E:/Programy/Projekty/Projekt Sdizo 1/Output/Drzewo/" + daneWyjsciowe, fstream::out);

        
        //Sprawd¿ czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wejœciowego!" << endl;
                return;
            }

        if (plikWyjsciowy.is_open()) 
        {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        }
        else 
            {
                cout << "Nie uda³o siê otworzyæ pliku wyjœciowego!" << endl;
                return;
            }

        switch (wybor) 
        {
            default:
                cout << "B³êdny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (plikWejsciowy.good()) 
                {
                    //Wczytaj wartoœæ z pliku
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    drzewo.dodaj(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    drzewo.dodaj(wartosc);
                }


                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    drzewo.usun(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 3:
                //Wype³nij tablicê wartoœciami
                while (plikWejsciowy.good()) 
                {
                    plikWejsciowy >> wartosc;
                    drzewo.dodaj(wartosc);
                }

                for (int i = 0; i < drzewo.rozmiarDrzewa; i++) 
                {
                    //Wykonaj funkcjê z pomiarem
                    czas.czasStart();
                    drzewo.sprawdzCzyIstnieje(rand() % 2000000 - 1000000);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;


            case 4:
                czas.czasStart();
                drzewo.wydrukujDrzewo();
                czas.czasStop();
                cout << "Czas wykonania: " << (1000.0 * czas.czasWykonania()) / czas.czestotliwosc << "ms" << endl;
                break;
        }

    }
}