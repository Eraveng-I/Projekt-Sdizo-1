#include "Drzewo.h"
#include <iostream>

using namespace std;

Drzewo::Drzewo() 
{
    rozmiarDrzewa = 0;

    //Kolory drzewa okreœlane jako " ", zanim s¹ zdefiniowane

    //Inicjaliacja stra¿nika
    straznik.kolor = 'B';
    straznik.rodzic = &straznik;
    straznik.lewo = &straznik;
    straznik.prawo = &straznik;
    korzen = &straznik;
}

Drzewo::~Drzewo() 
{
    if (korzen)
    {
        usunWszystko();
    }
}

void Drzewo::usunWszystko() 
{
    usunElement(korzen);

    //Inicjalizacja stra¿nika
    straznik.kolor = 'B';
    straznik.rodzic = &straznik;
    straznik.lewo = &straznik;
    straznik.prawo = &straznik;
    korzen = &straznik;

    //Ustaw rozmiar drzewa na 1
    Drzewo::rozmiarDrzewa = 0;
}

void Drzewo::usunElement(ElementDrzewa* elementDrzewa) 
{
    //Je¿eli element nie jest stra¿nikiem, usuñ jego dzieci
    //A nastepnie sam element
    if (elementDrzewa != &straznik) 
    {
        usunElement(elementDrzewa->lewo);
        usunElement(elementDrzewa->prawo);
        delete elementDrzewa;

        //Zmniejsz rozmiar drzewa
        Drzewo::rozmiarDrzewa--;
    }
    else 
        {
            cout << "Usuwany element jest stra¿nikiem!!!" << endl;
        }
}

void Drzewo::obrotWLewo(ElementDrzewa* elementDrzewa) 
{
    ElementDrzewa* y, * p;

    y = elementDrzewa->prawo;
    if (y != &straznik)
    {
        p = elementDrzewa->rodzic;
        elementDrzewa->prawo = y->lewo;
        if (elementDrzewa->prawo != &straznik)
        {
            elementDrzewa->prawo->rodzic = elementDrzewa;
        }

        y->lewo = elementDrzewa;
        y->rodzic = p;
        elementDrzewa->rodzic = y;

        if (p != &straznik)
        {
            if (p->lewo == elementDrzewa)
            {
                p->lewo = y;
            }
            else
                {
                    p->prawo = y;
                }
        }
        else
            {
                korzen = y;
            }
    }
}

void Drzewo::obrotWPrawo(ElementDrzewa* elementDrzewa) 
{
    ElementDrzewa* y, * p;

    y = elementDrzewa->lewo;
    if (y != &straznik)
    {
        p = elementDrzewa->rodzic;
        elementDrzewa->lewo = y->prawo;
        if (elementDrzewa->lewo != &straznik)
        {
            elementDrzewa->lewo->rodzic = elementDrzewa;
        }

        y->prawo = elementDrzewa;
        y->rodzic = p;
        elementDrzewa->rodzic = y;

        if (p != &straznik)
        {
            if (p->lewo == elementDrzewa)
            {
                p->lewo = y;
            }
            else
                {
                    p->prawo = y;
                }
        }
        else
            {
                korzen = y;
            }
    }
}

void Drzewo::dodaj(int wartosc) 
{
    ElementDrzewa* X, * Y;

    //Stworzenie nowego wêz³a dla drzewa
    X = new ElementDrzewa;
    X->lewo = &straznik;
    X->prawo = &straznik;
    X->rodzic = korzen;
    X->wartosc = wartosc;

    //Przypisanie korzenia jako X, je¿eli rodzic jest stra¿nikiem
    //W przeciwnym wypadku, zast¹pienie liœcia
    if (X->rodzic == &straznik) 
    {
        korzen = X;
    }
    else 
        {
            //Pêtla wyszukuje liœæ do zast¹pienia przez X
            //Zale¿nie od sytuacji zastêpuje prawy lub lewy liœæ drzewa
            while (true) 
            {
                //X zastêpuje lewy liœæ
                if (wartosc < X->rodzic->wartosc) 
                {
                    if (X->rodzic->lewo == &straznik) 
                    {
                        X->rodzic->lewo = X;
                        break;
                    }
                    X->rodzic = X->rodzic->lewo;

                    // X zastêpuje prawy liœæ
                }
                else
                    {
                        if (wartosc > X->rodzic->wartosc)
                        {
                            if (X->rodzic->prawo == &straznik) 
                            {
                                X->rodzic->prawo = X;
                                break;
                            }
                            X->rodzic = X->rodzic->prawo;

                            //Brak mo¿liwoœci zast¹pienia liœcia
                        }
                        else 
                            {
                                delete X;
                                return;
                            }
                    }
            }

            //Kolorowanie wêz³a na czerwono
            X->kolor = 'R';
            while ((X != korzen) && (X->rodzic->kolor == 'R')) 
            {
                if (X->rodzic == X->rodzic->rodzic->lewo) 
                {
                    Y = X->rodzic->rodzic->prawo;

                    //Przypadek 1
                    if (Y->kolor == 'R') 
                    {
                        X->rodzic->kolor = 'B';
                        Y->kolor = 'B';
                        X->rodzic->rodzic->kolor = 'R';
                        X = X->rodzic->rodzic;
                        continue;
                    }

                    //Przypadek 2
                    if (X == X->rodzic->prawo) 
                    {
                        X = X->rodzic;
                        obrotWLewo(X);
                    }

                    //Przypadek 3
                    X->rodzic->kolor = 'B';
                    X->rodzic->rodzic->kolor = 'R';
                    obrotWPrawo(X->rodzic->rodzic);
                    break;

                    //Przypadki lustrzane
                }
                else 
                    {
                        Y = X->rodzic->rodzic->lewo;

                        //Przypadek lustrzany 1
                        if (Y->kolor == 'R') 
                        {
                            X->rodzic->kolor = 'B';
                            Y->kolor = 'B';
                            X->rodzic->rodzic->kolor = 'R';
                            X = X->rodzic->rodzic;
                            continue;
                        }

                        //Przypadek lustrzany 2
                        if (X == X->rodzic->lewo) 
                        {
                            X = X->rodzic;
                            obrotWPrawo(X);
                        }

                        //Przypadek lustrzany 3
                        X->rodzic->kolor = 'B';
                        X->rodzic->rodzic->kolor = 'R';
                        obrotWLewo(X->rodzic->rodzic);
                        break;
                    }
            }
            korzen->kolor = 'B';

            //Zwiêkszenie rozmiaru drzewa o 1
            rozmiarDrzewa++;
        }
}

void Drzewo::usun(int wartosc) 
{
    ElementDrzewa* elementDrzewaDoUsuniecia;
    znajdzElement(wartosc, korzen, elementDrzewaDoUsuniecia);

    ElementDrzewa* W, * Y, * Z;

    if ((elementDrzewaDoUsuniecia->lewo == &straznik) || (elementDrzewaDoUsuniecia->prawo == &straznik))
    {
        Y = elementDrzewaDoUsuniecia;
    }
    else
        {
            Y = znajdzNastepnyElement(elementDrzewaDoUsuniecia);
        }

    if (Y->lewo != &straznik)
    {
        Z = Y->lewo;
    }
    else
        {
            Z = Y->prawo;
        }

    Z->rodzic = Y->rodzic;

    if (Y->rodzic == &straznik)
    {
        korzen = Z;
    }
    else
        {
            if (Y == Y->rodzic->lewo)
            {
                Y->rodzic->lewo = Z;
            }
            else
                {
                    Y->rodzic->prawo = Z;
                }
        }

    if (Y != elementDrzewaDoUsuniecia)
    {
        elementDrzewaDoUsuniecia->wartosc = Y->wartosc;
    }

    if (Y->kolor == 'B')   // Naprawa struktury drzewa czerwono-czarnego
    {
        while ((Z != korzen) && (Z->kolor == 'B'))
        {
            if (Z == Z->rodzic->lewo) 
            {
                W = Z->rodzic->prawo;

                //Przypadek 1
                if (W->kolor == 'R')
                {
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotWLewo(Z->rodzic);
                    W = Z->rodzic->prawo;
                }

                //Przypadek 2
                if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B'))
                {
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                //Przypadek 3
                if (W->prawo->kolor == 'B')
                {
                    W->lewo->kolor = 'B';
                    W->kolor = 'R';
                    obrotWPrawo(W);
                    W = Z->rodzic->prawo;
                }

                //Przypadek 4
                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = 'B';
                W->prawo->kolor = 'B';
                obrotWLewo(Z->rodzic);

                //Zakoñczenie pêtli
                Z = korzen;

                //Przypadki lustrzane
            }
            else
                {
                    W = Z->rodzic->lewo;

                    //Lustrzany przypadek 1
                    if (W->kolor == 'R')
                    {
                        W->kolor = 'B';
                        Z->rodzic->kolor = 'R';
                        obrotWLewo(Z->rodzic);
                        W = Z->rodzic->lewo;
                    }

                    //Lustrzany przypadek 2
                    if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B'))
                    {
                        W->kolor = 'R';
                        Z = Z->rodzic;
                        continue;
                    }

                    //Lustrzany przypadek 3
                    if (W->lewo->kolor == 'B')
                    {
                        W->prawo->kolor = 'B';
                        W->kolor = 'R';
                        obrotWLewo(W);
                        W = Z->rodzic->lewo;
                    }

                    //Lustrzany przypadek 4
                    W->kolor = Z->rodzic->kolor;
                    Z->rodzic->kolor = 'B';
                    W->lewo->kolor = 'B';
                    obrotWPrawo(Z->rodzic);

                    //Zakoñczenie pêtli
                    Z = korzen;
                }
        }
    }

    Z->kolor = 'B';

    /*if (Y->lewo == &straznik && Y->prawo == &straznik)
    {
        if (Z == Z->rodzic->lewo)
        {
            Z->rodzic->lewo = &straznik;
        }

        if (Z == Z->rodzic->prawo)
        {
            Z->rodzic->prawo = &straznik;
        }

        Z = &straznik;
    }*/

    delete Y;
}

void Drzewo::znajdzElement(int wartosc, ElementDrzewa* korzenElementuDrzewa, ElementDrzewa*& elementDoZnalezienia) 
{
    if (korzenElementuDrzewa != &straznik) 
    {
        if (korzenElementuDrzewa->wartosc == wartosc) 
        {
            elementDoZnalezienia = korzenElementuDrzewa;
            return;
        }
        znajdzElement(wartosc, korzenElementuDrzewa->lewo, elementDoZnalezienia);
        znajdzElement(wartosc, korzenElementuDrzewa->prawo, elementDoZnalezienia);
    }
}

void Drzewo::sprawdzCzyIstnieje(int wartosc) 
{
    bool znalezione = false;
    znajdzWartosc(wartosc, korzen, znalezione);

    if (znalezione) 
    {
        cout << "Wartoœæ " << wartosc << " wystêpuje w drzewie" << endl;
    }
    else 
        {
            cout << "Wartoœæ " << wartosc << " nie wystêpuje w drzewie" << endl;
        }
}

void Drzewo::znajdzWartosc(int wartosc, ElementDrzewa* korzenElementuDrzewa, bool& znalezione) 
{
    if (korzenElementuDrzewa != &straznik) 
    {
        if (korzenElementuDrzewa->wartosc == wartosc) 
        {
            znalezione = true;
            return;
        }
        znajdzWartosc(wartosc, korzenElementuDrzewa->lewo, znalezione);
        znajdzWartosc(wartosc, korzenElementuDrzewa->prawo, znalezione);
    }
}

void Drzewo::wydrukujDrzewo() 
{
    ElementDrzewa* X, * Y;
    X = korzen;
    int ilosc = 0;
    int ilosc_max = 0;
    int* wskaznik_ilosc = &ilosc;
    int* wskaznik_ilosc_max = &ilosc_max;
    
    ObliczRozmiar(X, wskaznik_ilosc, wskaznik_ilosc_max);

    int rozmiarTab = pow(2, ilosc_max) - 1;
    
    ElementDrzewa* TablicaDrzewa = new ElementDrzewa[rozmiarTab];

    for (int i = 0; i < rozmiarTab; i++)
    {
        TablicaDrzewa[i] = straznik;
    }

    TablicaDrzewa[0] = *X;

    for (int i = 0; 2*i+2 < rozmiarTab; i++)
    {
        //TablicaDrzewa[i] = straznik;
        if (TablicaDrzewa[i].lewo != &straznik)
        {
            TablicaDrzewa[2 * i + 1] = *TablicaDrzewa[i].lewo;
        }
        
        if (TablicaDrzewa[i].prawo != &straznik)
        {
            TablicaDrzewa[2 * i + 2] = *TablicaDrzewa[i].prawo;
        }
    }

    string odstep = " ";    //odstep 3 spacji
    int iloscStopni = 0;
    int potega2 = 1;

    for (potega2 = 1; potega2 - 1 < rozmiarTab; potega2 = potega2 * 2)
    {
        iloscStopni++;
    }

    potega2 = 1;

    cout << "Aktualny stan Drzewa:" << endl;
    //Je¿eli tablica nie ma elementów, wyœwietl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    //if (TablicaDrzewa != &straznik)
    if (korzen != &straznik)
    {
        for (int i = 0; i < rozmiarTab; i++)
        {
            if (i + 1 == potega2)
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
                    for (int l = pow(2, iloscStopni + 1); l > 0; l--)
                    {
                        cout << odstep;
                    }
                }

            /*if (i == 0)
            {
                cout << TablicaDrzewa[i].wartosc;
            }*/
            
            //TablicaDrzewa[i] = straznik;
            if (&TablicaDrzewa[i] != &straznik && TablicaDrzewa[i].wartosc != straznik.wartosc)
            {
                cout << TablicaDrzewa[i].wartosc;
                cout << TablicaDrzewa[i].kolor;
            }
            else
                {
                    cout << odstep;
                }
            //if (TablicaDrzewa[i] == straznik)
            //{
            //    cout << TablicaDrzewa[i].wartosc;
            //}
        }

        cout << endl;
    }
    else
        {
            cout << "    Drzewo nie ma ¿adnych elementów" << endl;
        }
}

void Drzewo::ObliczRozmiar(ElementDrzewa* korzenElementuDrzewa, int* wskaznik, int* wskaznik_max)
{
    int lokalna_ilosc = 0;

    if (korzenElementuDrzewa != &straznik)
    {
        *wskaznik = *wskaznik + 1;
        if (*wskaznik > *wskaznik_max)
        {
            *wskaznik_max = *wskaznik;
        }
        lokalna_ilosc = *wskaznik;
        ObliczRozmiar(korzenElementuDrzewa->lewo, wskaznik, wskaznik_max);
        *wskaznik = lokalna_ilosc;
        ObliczRozmiar(korzenElementuDrzewa->prawo, wskaznik, wskaznik_max);
    }

}

ElementDrzewa* Drzewo::znajdzNastepnyElement(ElementDrzewa* p) 
{
    ElementDrzewa* nastepnyElementDrzewa;

    if (p != &straznik) 
    {
        if (p->prawo != &straznik)
        {
            return znajdzNajmniejszyElementDrzewa(p->prawo);
        }
        else
            {
                nastepnyElementDrzewa = p->rodzic;
                while ((nastepnyElementDrzewa != &straznik) && (p == nastepnyElementDrzewa->prawo)) 
                {
                    p = nastepnyElementDrzewa;
                    nastepnyElementDrzewa = nastepnyElementDrzewa->rodzic;
                }
                return nastepnyElementDrzewa;
            }
    }
    return &straznik;
}

ElementDrzewa* Drzewo::znajdzNajmniejszyElementDrzewa(ElementDrzewa* p) 
{
    if (p != &straznik)
    {
        while (p->lewo != &straznik)
        {
            p = p->lewo;
        }
    }
    return p;
}