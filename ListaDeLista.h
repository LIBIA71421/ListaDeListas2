#pragma once

#include <iostream>
#include <string>

#include "Cabecera.h"
#include "Lista7.h"
#include "ListaVaciaException.h"

template<class T>
class ListaDeLista
{
private:
	Cabecera<T>* primer;
public:
	ListaDeLista();
	~ListaDeLista();
	void nuevoDatoEnLista(T* nombreLista, T* dato);
	void mostrar(void (*mostrarT)(T*));
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Cabecera<T>* aux);
};

template<class T>
ListaDeLista<T>::ListaDeLista()
{
	primer = NULL;
}

template<class T>
ListaDeLista<T>::~ListaDeLista()
{

}


template<class T>
void ListaDeLista<T>::nuevoDatoEnLista(T* nombreLista, T* dato)
{
	if (primer == NULL)
	{
		primer = new Cabecera<T>(nombreLista);
		primer->aumentarEnLista(dato);
	}
	else
	{
		Cabecera<T>* aux = primer;
		while (aux != NULL && (aux->getNombreLista() != nombreLista))
		{
			aux = aux->getSiguiente();
		}
		if (aux == NULL)
		{
			Cabecera<T>* nuevaLista = new Cabecera<T>(nombreLista);
			nuevaLista->aumentarEnLista(dato);
			nuevaLista->crearSiguiente(primer);
			primer = nuevaLista;
		}
		else
		{
			aux->aumentarEnLista(dato);
		}
	}
}

template<class T>
void ListaDeLista<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Cabecera<T>* recorrerLista = primer;
		while (recorrerLista != NULL)
		{
			(*mostrarT)(recorrerLista->getNombreLista());
			Lista7<T>* auxLista = recorrerLista->getLista();
			Par<T>* aux = auxLista->getPrimer();
			cout << "animales:" << endl;
			while (aux != NULL)
			{
				(*mostrarT)(aux->getDato());
				aux = aux->getSiguiente();
			}
			recorrerLista = recorrerLista->getSiguiente();
		}
	}
}



template<class T>
T* ListaDeLista<T>::busquedaSecuencialRecursiva(T* dato)
{
	Cabecera<T>* aux = primer;
	return buscarRecursivamente(dato, aux);
}

