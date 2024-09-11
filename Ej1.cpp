#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool comparar(Cola<char>& cola1,Cola<char>& cola2)
{
    int contador=0,iter=0;
    while (!cola1.esVacia())
    {
        if (!cola2.esVacia())
        {
            if (cola1.desencolar() == cola2.desencolar())
            {
                contador++;
            }
        }
        else{
            return false;
        }
        iter++;
    }
    if (iter==contador)
    {
        return true;
    }   
}

int main()
{
    Cola<char> cola1;
    Cola<char> cola2;

    cola1.encolar(1);
    cola1.encolar(2);
    
    cola2.encolar(1);
    cola2.encolar(2);

    if (comparar(cola1,cola2))
    {
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    
}