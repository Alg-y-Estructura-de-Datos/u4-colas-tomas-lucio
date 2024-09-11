#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminar(Cola<int>& cola, int n){
    Cola<int> aux;

    while (!cola.esVacia())
    {
        if (cola.peek()>n)
        {
            cola.desencolar();
        }
        else
        {
            aux.encolar(cola.desencolar());
        }
    }
    while (!aux.esVacia())
    {
        cola.encolar(aux.desencolar());
    }
    
    
}

int main()
{
    Cola<int> cola;
    cola.encolar(2);
    cola.encolar(5);
    cola.encolar(7);

    eliminar(cola,5);
    while (!cola.esVacia())
    {
        cout << cola.desencolar()<<" ";
    }
    
    return 0;
}