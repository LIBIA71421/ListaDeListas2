#pragma once

#include <sstream>
#include <iostream>
using namespace std;

class ListaVaciaException : public exception
{
private:
	string mensaje;
public:
	ListaVaciaException() {
		stringstream ss;
		ss << "la lista no tiene ningun item para borrar";
		mensaje = ss.str();
	}
	const char* what() const throw ()
	{
		return mensaje.c_str();
	}
};
