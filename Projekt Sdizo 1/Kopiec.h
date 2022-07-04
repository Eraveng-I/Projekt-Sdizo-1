#ifndef KOPIEC_H
#define KOPIEC_H

class Kopiec 
{
    public:
        int* tablicaKopca;
        unsigned int rozmiarKopca;

        Kopiec();

        ~Kopiec();

        void dodaj(int);

        void usunSzczyt();

        bool sprawdzCzyIstnieje(int);

        void wydrukujKopiec();

        void poprawStrukture();

        //int iloscPoziomow();
};

#endif //KOPIEC_H
