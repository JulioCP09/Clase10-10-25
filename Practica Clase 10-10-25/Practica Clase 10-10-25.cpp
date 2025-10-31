// Practica Clase 10-10-25.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ListaDoble.h"
using namespace std;

int main()
{
	//Crear la lista
    ListaDoble lista;

	//Variables
    bool Continuar = true;
    string Respuesta = "Si";
    int dato = 0;
	int datoBuscar = 0;
	int datoEliminar = 0;
	int valorViejo = 0;
	int valorNuevo = 0;
	int valorNodo = 0;

	//Llenar la lista
    while (Continuar)
    {
        cout << "Ingrese Dato" << endl;
        cin >> dato;
        lista.Insertar(dato);
        cout << "Desea continuar? Si/No" << endl;
        cin >> Respuesta;

        if (Respuesta == "No" || Respuesta == "no")
        {
            Continuar = false;
        }
        else
        {
            Continuar = true;
        }
    }
	//Mostrar la lista
	lista.Mostrar();

	//Metodos de la practica para examen
	
	//Buscar multiplos de un numero en la lista
	cout << "Ingrese un numero para buscar sus multiplos en la lista" << endl;
	cin >> datoBuscar;
	lista.BuscarMultiplosDe(datoBuscar);

	//Calcular el promedio de los nodos
	lista.PromedioDeNodos();

	/*//Insertar un dato en una posicion especifica
	cout << "Ingrese el dato a insertar" << endl;
	cin >> dato;
	cout << "Ingrese el valor del nodo donde desea insertar" << endl;
	cin >> valorNodo;
	lista.InsertarDondeSea(dato, valorNodo);
	
	//Mostrar la lista actualizada
	lista.Mostrar();

	
	//Buscar un dato en la lista
	cout << "Ingrese el dato a buscar" << endl;
	cin >> datoBuscar;
    lista.Buscar(datoBuscar);

	//Eliminar un dato de la lista
	cout << "Ingrese el dato a eliminar" << endl;
    cin >> datoEliminar;
	lista.Eliminar(datoEliminar);

	//Mostrar la lista actualizada
    lista.Mostrar();

	//Modificar un dato de la lista
	cout << "Ingrese el dato a modificar" << endl;
	cin >> valorViejo;
	cout << "Ingrese el nuevo valor" << endl;
	cin >> valorNuevo;
	lista.Modificar(valorViejo, valorNuevo);

	//Mostrar la lista actualizada
	lista.Mostrar();

	//Guardar la lista en un archivo
	lista.GuardarEnArchivo();

	//Guardar el promedio de los nodos en un archivo
	lista.GuardarElPromedio();

	//Leer la lista desde un archivo
	lista.LeerDesdeArchivo();*/
}