#pragma once

#include <iostream>
#include <string>

#include "Cabecera.h"
#include "Lista7.h"
#include "ListaVaciaException.h"

template<class T>
class ListadeListas2_7
{
private:
	Cabecera<T>* vec[60]; //cabecera vec[60];
	Cabecera<T>* primer; // int primer
	int ultimo;
public:
	ListadeListas2_7();
	~ListadeListas2_7();
	void insertarPrincipioLL(T* nombreLista, T* dato);
	void insertarPrincipio(T* nombreLista, T* dato);
	void eliminarElementoDado(T* nombreLista, T* dato);
	void mostrar(void (*mostrarT)(T*));
};

template<class T>
ListadeListas2_7<T>::ListadeListas2_7()
{
	primer = NULL;
}

template<class T>
ListadeListas2_7<T>::~ListadeListas2_7()
{

}

template<class T>
void ListadeListas2_7<T>::insertarPrincipioLL(T* nombreLista, T* dato)
{
	if (primer == NULL )
	{
		primer = new Cabecera<T>(nombreLista);
		primer->insertarPrincipioCab(dato);
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
			nuevaLista->insertarPrincipioCab(dato);
			nuevaLista->crearSiguiente(primer);
			primer = nuevaLista;
		}
		else
		{
			aux->insertarPrincipioCab(dato);
		}
	}
}
template<class T>
void ListadeListas2_7<T>::insertarPrincipio(T* nombreLista, T* dato)
{
	if (primer == -1 && ultimo == -1)
	{
		primer = new Cabecera<T>(nombreLista);
		primer->insertarPrincipioCab(dato);
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
			nuevaLista->insertarPrincipioCab(dato);
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
void ListadeListas2_7<T>::eliminarElementoDado(T* nombreLista, T* dato)
{
	if (primer == NULL)
	{
		primer = new Cabecera<T>(nombreLista);
		primer->eliminarEstudianteDeMateriaCab(dato);
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
			nuevaLista->eliminarEstudianteDeMateriaCab(dato);
			nuevaLista->crearSiguiente(primer);
			primer = nuevaLista;
		}
		else
		{
			aux->eliminarEstudianteDeMateriaCab(dato);
		}
	}
}

/*
ListaLista::InsertarPrincipioLL (LL, el, materia)

si(LL.primer == -1 && LL.ultimo == -1)
	   LL.primer = tam/2
	   LL.ultimo = tam/2
	   LL.vec[LL.primer].criterio = materia;
	   LL.vec[LL.primer].Lista->insertarPrincipio(el);

cc
	   int aux=LL.primer
	   mientras(materia ≠ LL.vec[aux].getmateria Y aux ≠ LL.Ultimo)
						   if(aux==TAM-1)
								   aux=0
						   c/c
								   aux++

	Si(materia==LL.vec[aux].getmateria)
			 LL.vec[aux].Lista->insertarPrincipio(el)
	c/c
		 Si(LL.primer== 0 )
					   Si (LL.ultimo != Tam-1) entonces  LL.primer=Tam-1;
						c/c  resp=´n´; // array_lleno
				 c/c
						 Si (LL.ultimo != LL.primer-1) entonces LL.primer= LL.primer-1
						 c/c  resp=´n´; //  array_lleno

				Si (resp!=´n´)
						 LL.vec[LL.primer].criterio = materia;
			 LL.vec[LL.primer].Lista->insertarPrincipio(el)
*/
template<class T>
void ListadeListas2_7<T>::mostrar(void (*mostrarT)(T*))
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
			cout << endl << "materia:" << endl;
			(*mostrarT)(recorrerLista->getNombreLista());
			Lista7<T>* auxLista = recorrerLista->getLista();
			Par<T>* aux = auxLista->getPrimer();
			cout << endl << "estudiantes:" << endl;
			while (aux != NULL)
			{
				(*mostrarT)(aux->getDato());
				aux = aux->getSiguiente();
			}
			recorrerLista = recorrerLista->getSiguiente();
		}
	}
}