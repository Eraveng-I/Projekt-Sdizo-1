#include "Czas.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

long long int Czas::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void Czas::czasStart() 
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&czestotliwosc);
    czasPoczatkowy = read_QPC();
}

void Czas::czasStop() 
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&czestotliwosc);
    czasKoncowy = read_QPC();
}

long long int Czas::czasWykonania() 
{
    return czasKoncowy - czasPoczatkowy;
}