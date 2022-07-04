#ifndef TABLICA_H
#define TABLICA_H

class Tablica {

    public:
        //Zmienne
        int* wskaznikTablicy;

        int rozmiarTablicy;

        //Metody
        Tablica();

        ~Tablica();

        void dodajNaPoczatek(int);

        void dodajNaKoniec(int wartosc);

        void dodajGdziekolwiek(int wartosc, int pozycja);

        void usunOstatni();

        void usunPierwszy();

        void usunKtorys(int pozycja);

        void wydrukujTablice();

        bool sprawdzCzyIstnieje(int wartosc);
};

#endif //TABLICA_H