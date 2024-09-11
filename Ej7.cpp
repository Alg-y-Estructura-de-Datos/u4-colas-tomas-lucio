#include <iostream>
#include "Cola/Cola.h"
using namespace std;


struct Documento {
    string nombre;
    int paginas;

    Documento(const string& nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar() const {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};


void mostrarCola(Cola<Documento>& cola1)
{
    Cola<Documento> aux;
    Documento dato;
    while (!cola1.esVacia())
    {
        dato = cola1.desencolar();
        aux.encolar(dato);
        dato.mostrar();
    }
    while (!aux.esVacia())
    {
        cola1.encolar(aux.desencolar());
    }
    
}

void agregarDocumento(Cola<Documento>& cola1)
{
    string nom;
    int pag;
    cout<<"ingrese el nombre del documento"<<endl;
    cin>>nom;
    cout<<"ingrese la cantidad  de paginas"<<endl;
    cin>>pag;
    Documento docu(nom,pag);
    cola1.encolar(docu);
}

void imprimirDocumento(Cola<Documento>& cola1)
{
    Documento doc;
    if (!cola1.esVacia())
    {
        doc = cola1.peek();
        cout << "imprimiendo..." <<endl;
        doc.mostrar();
        cola1.desencolar();
    }
    else{
        cout<<"no hay nada en la cola de impresion"<<endl;
    }
}

int main(){
    Cola<Documento> cola1;
    int op;
    do {
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Mostrar cola de impresion\n";
        cout << "2. Agregar nuevo documento a la cola\n";
        cout << "3. Imprimir siguiente documento\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                mostrarCola(cola1);
            break;
            case 2:
                agregarDocumento(cola1);
            break;
            case 3:
                imprimirDocumento(cola1);
            break;
            case 4:
                cout << "Saliendo del programa..." << endl;
            break;
            default:
                cout << "Opción invalida. Intentelo de nuevo." << endl;
            break;
        }
    } while (op != 4);

    return 0;
    
}