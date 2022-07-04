#ifndef DRZEWO_H
#define DRZEWO_H

#include <iostream>
#include "ElementDrzewa.h"

using namespace std;

class Drzewo 
{
    public:

        int rozmiarDrzewa;

        Drzewo();

        ~Drzewo();

        void usunWszystko();

        void dodaj(int);

        void usun(int);

        void obrotWLewo(ElementDrzewa*);

        void obrotWPrawo(ElementDrzewa*);

        void sprawdzCzyIstnieje(int);

        void wydrukujDrzewo();

        void ObliczRozmiar(ElementDrzewa* korzenElementuDrzewa, int* wskaznik, int* wskaznik_max);

    private:

        ElementDrzewa* korzen;

        ElementDrzewa straznik;

        void usunElement(ElementDrzewa*);

        void znajdzElement(int, ElementDrzewa*, ElementDrzewa*&);

        void znajdzWartosc(int, ElementDrzewa*, bool& znalezione);

        ElementDrzewa* znajdzNastepnyElement(ElementDrzewa*);

        ElementDrzewa* znajdzNajmniejszyElementDrzewa(ElementDrzewa*);

        

        
};

#endif //DRZEWO_H
