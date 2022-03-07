#pragma once

#include <iostream>

#include "Lista7.h"
using namespace std;

template<class T>
class Cabecera
{
private:
	Cabecera* siguiente;
	Lista7<T>* lista;
	T* nombreLista;
public:
	Cabecera(T* nombre);
	Cabecera();
	~Cabecera();
	T* getNombreLista();
	Lista7<T>* getLista();
	void setLista(Cabecera<T>* lista);
	Cabecera<T>* getSiguiente();
	void crearSiguiente(Cabecera<T>* lista);
	void insertarPrincipioCab(T* dato);
	void eliminarEstudianteDeMateriaCab(T* dato);
};

template<class T>
Cabecera<T>::Cabecera(T* nombre)
{
	this->nombreLista = nombre;
	lista = new Lista7<T>();
	siguiente = NULL;
}

template<class T>
Cabecera<T>::Cabecera()
{
	lista = NULL;
	siguiente = NULL;
}

template<class T>
Cabecera<T>::~Cabecera()
{

}

template<class T>
T* Cabecera<T>::getNombreLista()
{
	return nombreLista;
}

template<class T>
Lista7<T>* Cabecera<T>::getLista()
{
	return lista;
}

template<class T>
void Cabecera<T>::setLista(Cabecera<T>* lista)
{
	this->lista = lista;
}


template<class T>
Cabecera<T>* Cabecera<T>::getSiguiente()
{
	return siguiente;
}


template<class T>
void Cabecera<T>::crearSiguiente(Cabecera<T>* nuevoSig)
{
	siguiente = nuevoSig;
}

template<class T>
void Cabecera<T>::insertarPrincipioCab(T* dato)
{
	lista->insertarPrincipio(dato);
}

template<class T>
void Cabecera<T>::eliminarEstudianteDeMateriaCab(T* dato) {
	lista->eliminarElemDado(dato);
}