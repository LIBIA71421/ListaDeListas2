#pragma once

#include <iostream>
#include <string>

#include "Par.h"
#include "ListaVaciaException.h"

template<class T>
class Lista7
{
private:
	Par<T>* primer;
	Par<T>* ultimo;
public:
	Lista7();
	~Lista7();
	void leerArchivo();
	void insertarPrincipio(T* dato);
	void eliminarPrincipio();
	void insertarFinal(T* dato);
	void eliminarFinal();
	void mostrar(void (*mostrarT)(T*));
	T* busquedaSecuencialNoRecursiva(T* dato);
	T* busquedaSecuencialRecursiva(T* dato);
	T* buscarRecursivamente(T* dato, Par<T>* aux);
	Par<T>* getPrimer();
};

template<class T>
Lista7<T>::Lista7()
{
	primer = NULL;
	ultimo = NULL;
}

template<class T>
Lista7<T>::~Lista7()
{
	Par<T>* segundo;
	while (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete primer;
			ultimo = NULL;
			primer = NULL;
		}
		else
		{
			segundo = primer->getSiguiente();
			delete primer;
			primer = segundo;
		}
	}
}


template<class T>
void Lista7<T>::insertarPrincipio(T* dato)
{
	if (primer == NULL)
	{
		primer = new Par<T>(dato, NULL);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = new Par<T>(dato, NULL);
		primer = aux;
	}
}

template<class T>
void Lista7<T>::eliminarPrincipio()
{
	if (primer == NULL)
	{
		throw ListaVaciaException();
	}
	else if (primer == ultimo)
	{
		delete primer;
		primer = NULL;
		ultimo = NULL;
	}
	else
	{
		Par<T>* aux;
		aux = primer->getSiguiente();
		delete primer;
		primer = aux;
	}
}

template<class T>
void Lista7<T>::insertarFinal(T* dato)
{

	if (primer == NULL && ultimo == NULL)
	{
		primer = new Par<T>(dato);
		ultimo = primer;
	}
	else
	{
		Par<T>* aux = primer;
		primer = new Par<T>(dato);
		primer->crearSiguiente(aux);
	}
}
template<class T>
void Lista7<T>::eliminarFinal()
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	if (primer == ultimo)
	{
		delete primer;
		ultimo = NULL;
		primer = NULL;
	}
	else
	{
		Par<T>* aux = primer->getSiguiente();
		delete primer;
		primer = aux;
	}
}


template<class T>
void Lista7<T>::mostrar(void (*mostrarT)(T*))
{
	if (primer == NULL && ultimo == NULL)
	{
		throw ListaVaciaException();
	}
	else
	{
		Par<T>* aux = primer;
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			//cout << aux->getDato() << " -- ";
			aux = aux->getSiguiente();
		}
	}
}



template<class T>
T* Lista7<T>::busquedaSecuencialNoRecursiva(T* dato)
{
	Par<T>* aux = primer;
	T* datoEncontrado = NULL;
	while (aux != NULL)
	{
		if (*aux->getDato() == dato)
		{
			datoEncontrado = aux->getDato();
		}
		aux = aux->getSiguiente();
	}
	return datoEncontrado;
}


template<class T>
T* Lista7<T>::busquedaSecuencialRecursiva(T* dato)
{
	Par<T>* aux = primer;
	return buscarRecursivamente(dato, aux);
}

template<class T>
T* Lista7<T>::buscarRecursivamente(T* dato, Par<T>* aux)
{
	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		if (*aux->getDato() == dato)
		{
			return aux->getDato();
		}
		else
		{
			return buscarRecursivamente(dato, aux->getSiguiente());
		}
	}
}

template<class T>
Par<T>* Lista7<T>::getPrimer()
{
	return primer;
}
