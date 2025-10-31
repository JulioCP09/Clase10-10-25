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
	void Modificar(int valorViejo, int valorNuevo);
	void GuardarEnArchivo();
	void GuardarElPromedio();
	void LeerDesdeArchivo();
	void InsertarDondeSea(int valor, int valorNodo);

	//Metodos de la practica para examen
	void BuscarMultiplosDe(int numero);
	void PromedioDeNodos();
};
