#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() 
{
    Lista::pierwszyElement = NULL;
    Lista::aktualnyElement = NULL;
    Lista::ostatniElement = NULL;
    Lista::rozmiarListy = 0;
}

Lista::~Lista() 
{
    for (int i = 0; i < Lista::rozmiarListy; i++) 
    {
        //Przypisz kolejny element jako aktualny
        aktualnyElement = pierwszyElement->nastepny;
        //Usu� pierwszy element
        delete pierwszyElement;

        pierwszyElement = aktualnyElement;
    }
}

void Lista::dodajNaPoczatek(int wartosc) 
{
    //Sprawd�, czy istnieje element pocz�tkowy
    if (pierwszyElement == NULL) 
    {
        //Utw�rz nowy element i ustaw go jako element pocz�tkowy i ko�cowy
        pierwszyElement = new ElementListy(wartosc, NULL, NULL);
        ostatniElement = pierwszyElement;
    }
    else 
        {
            //Ustaw element ktory by� pierwszym jako aktualny
            aktualnyElement = pierwszyElement;
            //Zast�p pierwszy element nowym
            //Ustaw jego warto�� oraz element kolejny na element aktualny (by�y pierwszy)
            pierwszyElement = new ElementListy(wartosc, aktualnyElement, NULL);
            aktualnyElement->poprzedni = pierwszyElement;
        }

    //Zwi�ksz rozmiar listy
    rozmiarListy = rozmiarListy + 1;
}

void Lista::dodajNaKoniec(int wartosc) 
{
    //Sprawd�, czy istnieje element pocz�tkowy
    if (pierwszyElement == NULL) 
    {
        //Utw�rz nowy element i ustaw go jako element pocz�tkowy i ko�cowy
        ostatniElement = new ElementListy(wartosc, NULL, NULL);
        pierwszyElement = ostatniElement;
    }
    else 
        {
            //Ustaw element kt�ry by� ostatnim jako aktualny
            aktualnyElement = ostatniElement;
            //Zast�p ostatni element nowym
            //Ustaw jego warto�� oraz element poprzedni na element aktualny (by�y ostatni)
            ostatniElement = new ElementListy(wartosc, NULL, aktualnyElement);
            aktualnyElement->nastepny = ostatniElement;
        }

    //Zwi�ksz rozmiar listy o 1
    rozmiarListy++;
}

void Lista::dodajGdziekolwiek(int wartosc, int pozycja) 
{
    //Sprawd� czy w li�cie istnieje pozycja podana przez u�ytkownika
    if (pozycja < 0 || pozycja > rozmiarListy) 
    {
        cout << "W li�cie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawd� czy wybrana pozycja jest pierwsz�
    if (pozycja == 0) 
    {
        Lista::dodajNaPoczatek(wartosc);
        return;
    }

    //Sprawd� czy wybrana pozycja jest ostatni�
    if (pozycja == rozmiarListy) 
    {
        dodajNaKoniec(wartosc);
        return;
    }

    //Sprawd� w kt�rej po�owie listy znajduje si� wybrany element
    if (pozycja < rozmiarListy / 2)  //liczone od indeksu zerowego
    {
        //Przypisz za aktualny element pierwszy
        aktualnyElement = pierwszyElement;

        //Przesu� wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) 
        {
            aktualnyElement = aktualnyElement->nastepny;
        }
    }
    else 
        {
            //Przypisz za aktualny element ostatni
            aktualnyElement = ostatniElement;

            //Przesu� wszystkie elementy o jedn� pozycj� wstecz
            for (int i = 0; i < Lista::rozmiarListy - pozycja - 1; ++i) 
            {
                aktualnyElement = aktualnyElement->poprzedni;
            }
        }

    //Stw�rz nowy element listy z podanymi parametrami
    ElementListy* nowyElementListy = new ElementListy(wartosc, aktualnyElement, aktualnyElement->nastepny);

    //przypisz nowy element w odpowiednim miejscu tablicy
    aktualnyElement->nastepny->poprzedni = nowyElementListy;
    aktualnyElement->nastepny = nowyElementListy;

    //Zwi�ksz rozmiar listy
    rozmiarListy = rozmiarListy + 1;
}

void Lista::usunPierwszy() 
{
    //przypisz drugi element jako aktualny
    aktualnyElement = pierwszyElement->nastepny;

    //Usu� pierwszy element
    delete pierwszyElement;

    //Sprawd�, czy w li�cie s� jeszcze jakie� elementy
    //Je�eli tak, ustaw aktualny element jako pierwszy
    //Je�eli nie, wyzeruj elementy listy
    if (rozmiarListy > 1) 
    {
        aktualnyElement->poprzedni = NULL;
        pierwszyElement = aktualnyElement;
    }
    else 
        {
            aktualnyElement = NULL;
            pierwszyElement = NULL;
            ostatniElement = NULL;
        }

    //Zmniejsz rozmiar listy
    rozmiarListy--;
}

void Lista::usunOstatni() 
{
    //Przypisz przedostani element jako aktualny
    aktualnyElement = ostatniElement->poprzedni;
    //Usu� ostatni element
    delete ostatniElement;

    //Sprawd�, czy w li�cie s� jeszcze jakie� elementy
    //Je�eli tak, ustaw aktualny element jako ostatni
    //Je�eli nie, wyzeruj elementy listy
    if (rozmiarListy > 1) 
    {
        aktualnyElement->nastepny = NULL;
        ostatniElement = aktualnyElement;
    }
    else 
        {
            aktualnyElement = NULL;
            pierwszyElement = NULL;
            ostatniElement = NULL;
        }

    //Zmniejsz rozmiar listy
    rozmiarListy--;
}

void Lista::usunKtorys(int pozycja) 
{
    //Sprawd� czy w li�cie istnieje pozycja podana przez u�ytkownika
    if (pozycja < 0 || pozycja > rozmiarListy) 
    {
        cout << "W li�cie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawd� czy wybrana pozycja jest pierwsz�
    if (pozycja == 0) 
    {
        usunPierwszy();
        return;
    }

    //Sprawd� czy wybrana pozycja jest ostatni�
    if (pozycja == rozmiarListy - 1) 
    {
        usunOstatni();
        return;
    }

    //Sprawd� w kt�rej po�owie listy znajduje si� wybrany element
    if (pozycja < rozmiarListy / 2) 
    {
        //Przypisz za aktualny element pierwszy
        aktualnyElement = pierwszyElement;

        //Przesu� wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) 
        {
            aktualnyElement = aktualnyElement->nastepny;
        }
    }
    else 
        {
            //Przypisz za aktualny element ostatni
            aktualnyElement = ostatniElement;

            //Przesu� wszystkie elementy o jedn� pozycj� wstecz
            for (int i = 0; i < rozmiarListy - pozycja - 1; ++i) 
            {
                aktualnyElement = aktualnyElement->poprzedni;
            }
        }

    //Stw�rz nowy element listy z podanymi parametrami
    ElementListy* nowyElementListy = aktualnyElement->nastepny;

    //przypisz nowy element w odpowiednim miejscu tablicy
    aktualnyElement->nastepny = nowyElementListy->nastepny;
    aktualnyElement->nastepny->poprzedni = nowyElementListy;

    delete[]nowyElementListy;

    //Zmniejsz rozmiar listy
    rozmiarListy--;
}

bool Lista::sprawdzCzyIstnieje(int wartosc) 
{
    //Je�eli lista jest pusta, zwr�� false z automatu
    if (rozmiarListy == 0) 
    {
        return false;
    }

    //Przypisa pierwszy element jako aktualny
    aktualnyElement = pierwszyElement;

    //Przeszukaj list� pod k�tem warto�ci
    for (int i = 0; i < rozmiarListy; i++) 
    {
        if (aktualnyElement->wartosc == wartosc) 
        {
            cout << "Szukana warto��zajmuje w li�cie pozycj� [" << i << "]" << endl;
            return true;
        }

        aktualnyElement = aktualnyElement->nastepny;
    }

    //Je�eli warto�� nie wyst�pi�a w �adnej iteracji listy zwr�� false
    cout << "Szukana warto�� nie wyst�puje w li�cie" << endl;
    return false;
}

void Lista::wydrukujListe() 
{
    cout << "Aktualny stan listy:" << endl;

    //Ustaw jako akutualny element pierwszy element listy
    aktualnyElement = pierwszyElement;

    /*for (int i = 0; i < rozmiarListy; i++)
    {
        cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

        //Przypisz kolejny element listy jako aktualny
        aktualnyElement = aktualnyElement->nastepny;
    }*/

    if (rozmiarListy>0)
    {
        for (int i = 0; i < rozmiarListy; i++)
        {
            cout << "[" << i << "] " << aktualnyElement->wartosc << endl;

            //Przypisz kolejny element listy jako aktualny
            aktualnyElement = aktualnyElement->nastepny;
        }
    }
    else
        {
            cout << "    Lista nie ma �adnych element�w" << endl;
        }
}