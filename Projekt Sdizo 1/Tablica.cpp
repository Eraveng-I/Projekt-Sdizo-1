#include <iostream>
#include "Tablica.h"

using namespace std;

//Konstruktor inicjalizuje zmienne klasowe
Tablica::Tablica() 
{
    Tablica::wskaznikTablicy = NULL;
    Tablica::rozmiarTablicy = 0;
}

//Destruktor zwalnia pamiêæ tablicy, je¿eli istnieje
Tablica::~Tablica() 
{
    if (wskaznikTablicy != NULL) 
    {
        delete[]wskaznikTablicy;
    }
}

void Tablica::dodajNaPoczatek(int wartosc) 
{
    //Zaalokuj pamiêæ na tablicê wiêksza o jeden element ni¿ poprzednio
    //Przypisz podan¹ wartoœæ jako pierwszy element tablicy
    int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
    nowyWskaznikTablicy[0] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        nowyWskaznikTablicy[i + 1] = wskaznikTablicy[i];
    }

    //Zwolnij pamiêæ poprzedniej tablicy
    //Zast¹p wskaŸnik na g³owê tablicy nowym
    delete wskaznikTablicy;
    wskaznikTablicy = nowyWskaznikTablicy;

    //Zwiêksz rozmiar tablicy o 1
    rozmiarTablicy++;
}

void Tablica::dodajNaKoniec(int wartosc) 
{
    //Zaalokuj pamiêæ na tablicê wiêksza o jeden element ni¿ poprzednio
    //Przypisz podan¹ wartoœæ jako ostatni element tablicy
    int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
    nowyWskaznikTablicy[rozmiarTablicy] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        nowyWskaznikTablicy[i] = wskaznikTablicy[i];
    }

    //Zwolnij pamiêæ poprzedniej tablicy
    //Zast¹p wskaŸnik na g³owê tablicy nowym
    delete wskaznikTablicy;
    wskaznikTablicy = nowyWskaznikTablicy;

    //Zwiêksz rozmiar tablicy o 1
    rozmiarTablicy++;
}

void Tablica::dodajGdziekolwiek(int wartosc, int pozycja) 
{
    //SprawdŸ, czy wybrana pozycja znajduje siê w tablicy
    //Je¿eli nie, anuluj dodawanie
    if (pozycja < 0 || pozycja > rozmiarTablicy) 
    {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    }
    else 
        {
            //Zaalokuj pamiêæ na tablicê wiêksza o jeden element ni¿ poprzednio
            //Przypisz podan¹ wartoœæ jako element tablicy na wybranej pozycji
            int* nowyWskaznikTablicy = new int[rozmiarTablicy + 1];
            nowyWskaznikTablicy[pozycja] = wartosc;

            //Przepisz dane ze starej tablicy do nowej
            //Przerwij przed wybran¹ pozycj¹
            for (int i = 0; i < pozycja; i++) 
            {
                nowyWskaznikTablicy[i] = wskaznikTablicy[i];
            }

            //Uzupe³nij dane w tablicy po wybranej pozycji
            //Przepisz dane ze starej tablicy do nowej
            for (int i = pozycja; i < rozmiarTablicy; i++) 
            {
                nowyWskaznikTablicy[i + 1] = wskaznikTablicy[i];
            }

            //Zwolnij pamiêæ poprzedniej tablicy
            //Zast¹p wskaŸnik na g³owê tablicy nowym
            delete wskaznikTablicy;
            wskaznikTablicy = nowyWskaznikTablicy;

            //Zwiêksz rozmiar tablicy o 1
            rozmiarTablicy++;
        }
}

void Tablica::usunOstatni() 
{
    //SprawdŸ, czy tablica nie jest pusta
    if (rozmiarTablicy > 0) 
    {
        //Zaalokuj pamiêæ na tablicê mniejsz¹ o jeden element ni¿ poprzednio
        int* nowyWskaznikTablicy = new int[rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza ostatnim
        for (int i = 0; i < rozmiarTablicy - 1; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i];
        }

        //zwolnij pamiêæ po starym wskaŸniku
        //Przypisz nowy wskaŸnik na jego miejsce
        delete[] wskaznikTablicy;
        wskaznikTablicy = nowyWskaznikTablicy;

        //Zmniejsz rozmiar tablicy o 1
        rozmiarTablicy--;
    }
    else 
        {
            cout << "W tablicy nie ma ¿adnego elementu!" << endl;
        }
}

void Tablica::usunPierwszy() 
{
    //SprawdŸ, czy tablica nie jest pusta
    if (rozmiarTablicy > 0) 
    {
        //Zaalokuj pamiêæ na tablicê mniejsz¹ o jeden element ni¿ poprzednio
        int* nowyWskaznikTablicy = new int[rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza pierwszym
        for (int i = 0; i < rozmiarTablicy - 1; i++) 
        {
            nowyWskaznikTablicy[i] = wskaznikTablicy[i + 1];
        }

        //zwolnij pamiêæ po starym wskaŸniku
        //Przypisz nowy wskaŸnik na jego miejsce
        delete[] wskaznikTablicy;
        wskaznikTablicy = nowyWskaznikTablicy;

        //Zmniejsz rozmiar tablicy o 1
        rozmiarTablicy--;
    }
    else 
        {
            cout << "W tablicy nie ma ¿adnego elementu!" << endl;
        }
}

void Tablica::usunKtorys(int pozycja) 
{
    //SprawdŸ, czy tablica nie jest pusta
    //Sprawd¿ czy pozycja nie wykracza poza tablicê
    if (rozmiarTablicy > 0 || pozycja > 0 || pozycja < rozmiarTablicy) 
    {
        //Zaalokuj pamiêæ na tablicê mniejsz¹ o jeden element ni¿ poprzednio
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

        //zwolnij pamiêæ po starym wskaŸniku
        //Przypisz nowy wskaŸnik na jego miejsce
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
    //Przeszukaj tablicê pod k¹tem wartoœci
    for (int i = 0; i < rozmiarTablicy; i++) 
    {
        //Je¿eli wartoœæ wyst¹pi w iteracji zwróc true
        if (wskaznikTablicy[i] == wartosc) {
            cout << "Szukana wartoœæ zajmuje w tablicy pozycjê [" << i << "]" << endl;
            return true;
        }
    }
    //Je¿eli wartoœæ nie wyst¹pi³a w ¿adnej iteracji tabeli zwróæ false
    cout << "Szukana wartoœæ nie wystêpuje w tablicy" << endl;
    return false;
}

void Tablica::wydrukujTablice() 
{
    cout << "Aktualny stan tablicy:" << endl;
    //Je¿eli tablica nie ma elementów, wyœwietl komunikat
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
            cout << "    Tablica nie ma ¿adnych elementów" << endl;
        }
}