#include <iostream>
#include "Tablica.h"

using namespace std;

//Konstruktor inicjalizuje zmienne klasowe
Tablica::Tablica() 
{
    Tablica::wskaznikTablicy = NULL;
    Tablica::rozmiarTablicy = 0;
}

//Destruktor zwalnia pami�� tablicy, je�eli istnieje
Tablica::~Tablica() 
{
    if (wskaznikTablicy != NULL) 
    {
        delete[]wskaznikTablicy;
    }
}

void Tablica::dodajNaPoczatek(int wartosc) 
{
    //Zaalokuj pami�� na tablic� wi�ksza o jeden element ni� poprzednio
    //Przypisz podan� warto�� jako pierwszy element tablicy
    int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
    nowyWskaznikTablicy[0] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        nowyWskaznikTablicy[i + 1] = wskaznikTablicy[i];
    }

    //Zwolnij pami�� poprzedniej tablicy
    //Zast�p wska�nik na g�ow� tablicy nowym
    delete wskaznikTablicy;
    wskaznikTablicy = nowyWskaznikTablicy;

    //Zwi�ksz rozmiar tablicy o 1
    rozmiarTablicy++;
}

void Tablica::dodajNaKoniec(int wartosc) 
{
    //Zaalokuj pami�� na tablic� wi�ksza o jeden element ni� poprzednio
    //Przypisz podan� warto�� jako ostatni element tablicy
    int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
    nowyWskaznikTablicy[rozmiarTablicy] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        nowyWskaznikTablicy[i] = wskaznikTablicy[i];
    }

    //Zwolnij pami�� poprzedniej tablicy
    //Zast�p wska�nik na g�ow� tablicy nowym
    delete wskaznikTablicy;
    wskaznikTablicy = nowyWskaznikTablicy;

    //Zwi�ksz rozmiar tablicy o 1
    rozmiarTablicy++;
}

void Tablica::dodajGdziekolwiek(int wartosc, int pozycja) 
{
    //Sprawd�, czy wybrana pozycja znajduje si� w tablicy
    //Je�eli nie, anuluj dodawanie
    if (pozycja < 0 || pozycja > rozmiarTablicy) 
    {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    }
    else 
        {
            //Zaalokuj pami�� na tablic� wi�ksza o jeden element ni� poprzednio
            //Przypisz podan� warto�� jako element tablicy na wybranej pozycji
            int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
            nowyWskaznikTablicy[pozycja] = wartosc;

            //Przepisz dane ze starej tablicy do nowej
            //Przerwij przed wybran� pozycj�
            for (int i = 0; i < pozycja; i++) 
            {
                nowyWskaznikTablicy[i] = wskaznikTablicy[i];
            }

            //Uzupe�nij dane w tablicy po wybranej pozycji
            //Przepisz dane ze starej tablicy do nowej
            for (int i = pozycja; i < rozmiarTablicy; i++) 
            {
                nowyWskaznikTablicy[i + 1] = wskaznikTablicy[i];
            }

            //Zwolnij pami�� poprzedniej tablicy
            //Zast�p wska�nik na g�ow� tablicy nowym
            delete wskaznikTablicy;
            wskaznikTablicy = nowyWskaznikTablicy;

            //Zwi�ksz rozmiar tablicy o 1
            rozmiarTablicy++;
        }
}

void Tablica::usunOstatni() 
{
    //Sprawd�, czy tablica nie jest pusta
    if (rozmiarTablicy > 0) 
    {
        //Zaalokuj pami�� na tablic� mniejsz� o jeden element ni� poprzednio
        int* nowyWskaznikTablicy = new int[rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza ostatnim
        for (int i = 0; i < rozmiarTablicy - 1; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i];
        }

        //zwolnij pami�� po starym wska�niku
        //Przypisz nowy wska�nik na jego miejsce
        delete[] wskaznikTablicy;
        wskaznikTablicy = nowyWskaznikTablicy;

        //Zmniejsz rozmiar tablicy o 1
        rozmiarTablicy--;
    }
    else 
        {
            cout << "W tablicy nie ma �adnego elementu!" << endl;
        }
}

void Tablica::usunPierwszy() 
{
    //Sprawd�, czy tablica nie jest pusta
    if (rozmiarTablicy > 0) 
    {
        //Zaalokuj pami�� na tablic� mniejsz� o jeden element ni� poprzednio
        int* nowyWskaznikTablicy = new int[rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza pierwszym
        for (int i = 0; i < rozmiarTablicy - 1; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i + 1];
        }

        //zwolnij pami�� po starym wska�niku
        //Przypisz nowy wska�nik na jego miejsce
        delete[] wskaznikTablicy;
        wskaznikTablicy = nowyWskaznikTablicy;

        //Zmniejsz rozmiar tablicy o 1
        rozmiarTablicy--;
    }
    else 
        {
            cout << "W tablicy nie ma �adnego elementu!" << endl;
        }
}

void Tablica::usunKtorys(int pozycja) 
{
    //Sprawd�, czy tablica nie jest pusta
    //Sprawd� czy pozycja nie wykracza poza tablic�
    if (rozmiarTablicy > 0 || pozycja > 0 || pozycja < rozmiarTablicy) 
    {
        //Zaalokuj pami�� na tablic� mniejsz� o jeden element ni� poprzednio
        int* nowyWskaznikTablicy = new int[rozmiarTablicy - 1];

        //Przepisz elementy do wybranej pozycji
        for (int i = 0; i < pozycja; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i];
        }

        //Przepisz elementy po wybranej pozycji
        for (int i = pozycja; i < rozmiarTablicy - 1; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i + 1];
        }

        //zwolnij pami�� po starym wska�niku
        //Przypisz nowy wska�nik na jego miejsce
        delete[] wskaznikTablicy;
        wskaznikTablicy = nowyWskaznikTablicy;

        //Zmniejsz rozmiar tablicy o 1
        rozmiarTablicy--;
    }
    else
        {
            cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
        }
}

bool Tablica::sprawdzCzyIstnieje(int wartosc) 
{
    //Przeszukaj tablic� pod k�tem warto�ci
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        //Je�eli warto�� wyst�pi w iteracji zwr�c true
        if (wskaznikTablicy[i] == wartosc) {
            cout << "Szukana warto��zajmuje w tablicy pozycj� [" << i << "]" << endl;
            return true;
        }
    }
    //Je�eli warto�� nie wyst�pi�a w �adnej iteracji tabeli zwr�� false
    cout << "Szukana warto�� nie wyst�puje w tablicy" << endl;
    return false;
}

void Tablica::wydrukujTablice() 
{
    cout << "Aktualny stan tablicy:" << endl;
    //Je�eli tablica nie ma element�w, wy�wietl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if (wskaznikTablicy != NULL) 
    {
        for (int i = 0; i < rozmiarTablicy; i++) 
        {
            cout << "    [" << i << "] " << wskaznikTablicy[i] << endl;
        }
    }
    else 
        {
            cout << "    Tablica nie ma �adnych element�w" << endl;
        }
}