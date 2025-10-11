#pragma once
#include "NodoDoble.h"

class ListaDoble
{
public:
	NodoDoble* head; //Puntero al primer nodo de la lista
	ListaDoble(); //Constructor

	//Metodos
	void Insertar(int valor);
	void Mostrar();
	void Buscar(int valor);
	void Eliminar(int valor);
};

