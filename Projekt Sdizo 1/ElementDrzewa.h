#ifndef ELEMENT_DRZEWA_H
#define ELEMENT_DRZEWA_H

class ElementDrzewa 
{
    public:
        ElementDrzewa* rodzic;
        ElementDrzewa* lewo;
        ElementDrzewa* prawo;

        char kolor;
        int wartosc;
};

#endif //ELEMENT_DRZEWA_H
