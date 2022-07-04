#include <iostream>
#include "Kopiec.h"

using namespace std;

Kopiec::Kopiec() 
{
    Kopiec::tablicaKopca = NULL;
    Kopiec::rozmiarKopca = 0;
}

Kopiec::~Kopiec() 
{
    if (Kopiec::rozmiarKopca > 0) 
    {
        delete[]tablicaKopca;
    }
}

void Kopiec::dodaj(int wartosc) 
{
        //Stwórz now¹ tablicê wiêksz¹ o jeden element
        int* nowaTablica = new int[rozmiarKopca + 1];

        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < rozmiarKopca; i++) 
        {
            nowaTablica[i] = tablicaKopca[i];
        }

        //Dodanie wybranej wartoœci do kopca
        nowaTablica[rozmiarKopca] = wartosc;

        //Usuñ star¹ tablicê
        delete[]tablicaKopca;

        //Zast¹p star¹ tablicê now¹
        tablicaKopca = nowaTablica;

        //Popraw kolejnoœæ elementów w kopcu
        Kopiec::poprawStrukture();

        //Zwiêksz rozmiar kopca
        rozmiarKopca++;
}

void Kopiec::usunSzczyt() 
{
    int tymczasowa = 0;

    if (rozmiarKopca > 1)
    {
        //Stwórz now¹ tablicê, pomniejszon¹ o jeden element
        int* nowaTablicaKopca = new int[rozmiarKopca - 1];

        //Wstaw ostatni liœæ na szczyt
        nowaTablicaKopca[0] = tablicaKopca[rozmiarKopca - 1];


        //Przepisz elementy z starej tablicy do nowej 
        for (int k = 1; k < rozmiarKopca - 1; k++)
        {
            nowaTablicaKopca[k] = tablicaKopca[k];
        }

        //usuñ star¹ tablicê i przypisz na jej miejsce now¹
        delete[]tablicaKopca;
        tablicaKopca = nowaTablicaKopca;
    }
    else
        {
            delete[]tablicaKopca;
            tablicaKopca = NULL;
        }

    //Zmniejsz rozmiar tablicy
    if (rozmiarKopca > 0)
    {
        rozmiarKopca--;
    }

    //sprawdzamy kopiec od szczytu
    for (int k = 0; k < rozmiarKopca;) 
    {
        if (2 * k + 1 <= rozmiarKopca - 1)//sprawdzamy czy istnieje lewy potomek
        {
            if (2 * k + 2 <= rozmiarKopca - 1)//sprawdzamy czy istnieje prawy potomek
            {
                if (tablicaKopca[2 * k + 2] > tablicaKopca[2 * k + 1])//sprawdzamy czy wiêkszy od lewego
                {
                    if (tablicaKopca[2 * k + 2] > tablicaKopca[k])//sprawdzamy czy wymiana z prawym
                    {
                        tymczasowa = tablicaKopca[2 * k + 2];
                        tablicaKopca[2 * k + 2] = tablicaKopca[k];
                        tablicaKopca[k] = tymczasowa;
                    }

                    k = 2 * k + 2;
                }
                else
                    {
                        if (tablicaKopca[2 * k + 1] > tablicaKopca[k])//sprawdzamy czy wymiana z lewym
                        {
                            tymczasowa = tablicaKopca[2 * k + 1];
                            tablicaKopca[2 * k + 1] = tablicaKopca[k];
                            tablicaKopca[k] = tymczasowa;
                        }

                        k = 2 * k + 1;
                    }
            }
            else
                {
                    if (tablicaKopca[2 * k + 1] > tablicaKopca[k])//sprawdzamy czy wymiana z lewym
                    {
                        tymczasowa = tablicaKopca[2 * k + 1];
                        tablicaKopca[2 * k + 1] = tablicaKopca[k];
                        tablicaKopca[k] = tymczasowa;
                    }

                    k = 2 * k + 1;
                }
        }
        else
            {
                break;
            }
    }
    return;
}

bool Kopiec::sprawdzCzyIstnieje(int wartosc) 
{
    //Przeszukaj tablicê pod k¹tem wartoœci
    for (int i = 0; i < rozmiarKopca; i++) 
    {
        //Je¿eli wartoœæ wyst¹pi w iteracji zwróc true
        if (tablicaKopca[i] == wartosc) 
        {
            cout << "Szukana wartoœæ zajmuje w tablicy kopca pozycjê [" << i << "]" << endl;
            return true;
        }
    }
    //Je¿eli wartoœæ nie wyst¹pi³a w ¿adnej iteracji tabeli zwróæ false
    cout << "Szukana wartoœæ nie wystêpuje w kopcu" << endl;
    return false;
}

/*
                       0
         1                         2
   3           4             5             6
7     8     9     10     11     12     13     14
*/
void Kopiec::wydrukujKopiec() 
{
    string odstep = "   ";    //odstep 3 spacji
    int iloscStopni = 0;
    int potega2 = 1;

    for (potega2 = 1;potega2-1<rozmiarKopca;potega2=potega2*2)
    {
        iloscStopni++;
    }

    potega2 = 1;

    cout << "Aktualny stan kopca:" << endl;
    //Je¿eli tablica nie ma elementów, wyœwietl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if (tablicaKopca != NULL) 
    {
        for (int i = 0; i < rozmiarKopca; i++) 
        {
            if (i+1 == potega2)
            {
                cout << endl;
                iloscStopni--;
                potega2 = potega2 * 2;

                for (int l = pow(2, iloscStopni); l > 0; l--)
                {
                    cout << odstep;
                }
            }
            else
                {
                    for (int l = pow(2, iloscStopni+1); l > 0; l--)
                    {
                        cout << odstep;
                    }
                }

            cout << tablicaKopca[i];
        }

        cout << endl;
    }
    else 
        {
            cout << "    Tablica kopca nie ma ¿adnych elementów" << endl;
        }
}

void Kopiec::poprawStrukture() 
{
    //Zmienna pomocnicza do pêtli sortuj¹cej
    int tymczasowa = 0;
    int k = 999;

    //Pêtla sortuj¹ca, uk³adaj¹ca elementy kopca w odpowiedniej kolejnoœci
    //
    for (int i = rozmiarKopca; 0 < i; ) 
    {
        k = floor((i - 1) / 2);

        if (tablicaKopca[k] <= tablicaKopca[i]) 
        {
            tymczasowa = tablicaKopca[k];
            tablicaKopca[k] = tablicaKopca[i];
            tablicaKopca[i] = tymczasowa;
        }

        i = k;
    }
}