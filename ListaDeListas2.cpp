#include <iostream>
using namespace std;
#include "Lista7.h"
#include "Par.h"
#include "ListaDeLista.h"
#include "ListaDeListas2.h"

class Animales {
private:
    string nombre;
public:
    Animales(string nombre);
    void mostrar();
    void mostrar(Animales* animal);
};
Animales::Animales(string name){    nombre = name; }
void Animales::mostrar() { cout << "nombre" << nombre; }
void Animales::mostrar(Animales* animal) { if (animal != NULL) { animal->mostrar(); } }





int main()
{
/*  string v = "v";
    string f = "f";

    Lista7<string>* x = new Lista7<string>();

    x->insertarPrincipio(&v);
    x->insertarPrincipio(&f);

    string n = "loro";
    ListaDeLista<string>* lista;
    Animales* loro = new Animales(n);
    lista->nuevoDatoEnLista(&v,&n);*/

    return 0;
}

