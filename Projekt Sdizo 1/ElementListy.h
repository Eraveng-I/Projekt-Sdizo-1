#ifndef ELEMENTLISTY_H
#define ELEMENTLISTY_H

class ElementListy 
{
    public:
        ElementListy* nastepny;
        ElementListy* poprzedni;
        int wartosc;

        ElementListy(int, ElementListy*, ElementListy*);
};

#endif //ELEMENTLISTY_H
