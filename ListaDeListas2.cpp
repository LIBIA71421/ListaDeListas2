#include <iostream>
using namespace std;
#include "Lista7.h"

static void mostrarCadena(string * cadena) {
    cout << *cadena << " ";
}
static int* convertirAEntero(string linea) {
    return new int(stoi(linea));
}
static void mostrarEntero(int* entero) {
    cout << *entero << endl;
}
int main() {
    Lista7<string> lista;
    lista.insertarPrincipio(new string("vaca"));
    lista.insertarPrincipio(new string("puerco"));
    lista.insertarFinal(new string("rana"));
    lista.insertarFinal(new string("loro"));
    lista.insertarFinal(new string("zorro"));
    lista.mostrar(mostrarCadena);
    cout << endl;
    
    lista.eliminarElemDado(new string("rana"));
    lista.mostrar(mostrarCadena);
    cout << endl;

    return 0;
}
/*
int main()
{

    //PRIMERA MANERA

    Lista7<string> lista;
    lista.insertarPrincipio(new string("vaca"));
    lista.insertarPrincipio(new string("puerco"));
    lista.insertarFinal(new string("rana"));
    lista.insertarFinal(new string("loro"));
    lista.insertarFinal(new string("zorro"));
    lista.mostrar(mostrarCadena);
    cout << endl;

    lista.eliminarPrincipio();

    lista.mostrar(mostrarCadena);
    cout << endl;

    lista.eliminarFinal();

    lista.mostrar(mostrarCadena);
    cout << endl;

    string* encontrado = lista.busquedaSecuencialNoRecursiva(new string("vaca"));
    if (encontrado != NULL) {
        cout << "encontrado: " << *encontrado << endl;
    }

    string* encontradoRecursivo = lista.busquedaSecuencialRecursiva(new string("rana"));
    if (encontradoRecursivo != NULL) {
        cout << "encontradoRecursivo: " << *encontradoRecursivo << endl;
    }

    lista.eliminarElemDado(new string("rana"));
    lista.mostrar(mostrarCadena);
    cout << endl;

    Lista7<int> listaEnteros;
    //listaEnteros.leerArchivo("10000_Numeros(2).txt");
    listaEnteros.leerArchivo("10000_Numeros(2).txt", convertirAEntero);

    //listaEnteros.mostrar(mostrarEntero);
    
    return 0;
}

*/