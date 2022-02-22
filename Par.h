#pragma once

#include <iostream>
using namespace std;

template<class T>
class Par
{
private:
	T* dato;
	Par* siguiente;
public:
	Par(T* dato,Par* s);
	Par();
	~Par();
	T* getDato();
	void setDato(T* dato);
	void setSiguiente(Par<T>* siguiente);
	Par<T>* getSiguiente();
};

template<class T>
Par<T>::Par(T* dato,Par* s)
{
	this->dato = dato;
	siguiente = s;
}

template<class T>
Par<T>::Par()
{
	dato = NULL;
	siguiente = NULL;
}

template<class T>
Par<T>::~Par()
{

}

template<class T>
T* Par<T>::getDato()
{
	return dato;
}

template<class T>
void Par<T>::setDato(T* dato)
{
	this->dato = dato;
}


template<class T>
Par<T>* Par<T>::getSiguiente()
{
	return siguiente;
}


 template<class T>
 void Par<T>::setSiguiente(Par<T>* siguiente) {
	 this->siguiente = siguiente;
 }
