#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma region Constructor
ListaDoble::ListaDoble() : head(nullptr)
{
}
#pragma endregion

#pragma region Metodo Insertar

void ListaDoble::Insertar(int valor) 
{
	//Verificar si el valor ya existe en la lista
	NodoDoble* actual = head;
	while (actual != nullptr) 
	{ 
		//Recorrer la lista
		if (actual->dato == valor) 
		{
			//El valor ya existe
			cout << "El valor " << valor << " ya existe en la lista, no se permiten duplicados." << endl;
			return; // Salir del método sin insertar el valor duplicado
		}
		else 
		{
			actual = actual->siguiente; //Avanzar al siguiente nodo
		}
	}
	//Crear el nuevo nodo
	NodoDoble* nuevo = new NodoDoble(valor);
	if (head != nullptr)//LISTA CONTIENE ELEMENTOS		
	{
		head->anterior = nuevo;			
		nuevo->siguiente = head;
	}
	head = nuevo;

}
#pragma endregion

#pragma region Metodo Mostrar

void ListaDoble::Mostrar() 
{
	NodoDoble* actual = head;
	while (actual != nullptr)
	{
		cout << actual->dato << " "; //Mostrar el dato del nodo actual
		//Mostrar las direcciones de memoria
		cout << "Direc actual" << actual << " ";
		cout << "Direc anterior" << actual->anterior << " ";
		cout << "Direc siguiente" << actual->siguiente << " ";
		cout << endl;
		actual = actual->siguiente; //Avanzar al siguiente nodo
	}
}
#pragma endregion

#pragma region Metodo Buscar

void ListaDoble::Buscar(int valor) 
{
	NodoDoble* actual = head;
	bool encontrado = false;
	int posicion = 0;

	while (actual != nullptr && !encontrado)
	{
		posicion++; //Incrementar la posición en cada iteración

		//Verificar si el dato del nodo actual coincide con el valor buscado
		if (actual->dato == valor)
		{
			encontrado = true;
		}
		else
		{
			actual = actual->siguiente;
		}
	}

	//Mostrar el resultado de la búsqueda
	if (encontrado)
	{
		cout << "El valor " << valor << " fue encontrado en la posicion: " << posicion << endl;
	}
	else
	{
		cout << "El valor " << valor << " no fue encontrado en la lista" << endl;
	}
}
#pragma endregion

#pragma region Metodo Eliminar

void ListaDoble::Eliminar(int valor)
{
	NodoDoble* actual = head; //Nodo actual para recorrer la lista
	NodoDoble* anterior = nullptr; //Nodo anterior para mantener la referencia al nodo previo
	bool encontrado = false; 

	//Buscar el nodo a eliminar
	while (actual != nullptr && !encontrado)
	{
		//Verificar si el dato del nodo actual coincide con el valor a eliminar
		if (actual->dato == valor)
		{
			encontrado = true;
		}
		else
		{
			anterior = actual;
			actual = actual->siguiente;
		}
	}

	//Eliminar el nodo si fue encontrado
	if (encontrado)
	{
		if (actual == head) //Eliminar el primer nodo
		{
			head = head->siguiente; 
			if (head != nullptr) 
			{
				head->anterior = nullptr;
			}
		}
		else //Eliminar un nodo que no es el primero
		{
			anterior->siguiente = actual->siguiente;  
			if (actual->siguiente != nullptr) 
			{
				actual->siguiente->anterior = anterior;
			}
		}
		delete actual; // Liberar la memoria del nodo eliminado
		cout << "El valor " << valor << " ha sido eliminado de la lista." << endl;
	}
	else
	{
		cout << "El valor " << valor << " no fue encontrado en la lista." << endl;
	}
}
#pragma endregion

#pragma region Metodo Modificar

void ListaDoble::Modificar(int valorViejo, int valorNuevo)
{
	NodoDoble* actual = head;
	bool encontrado = false;

	//Buscar el nodo a modificar
	while (actual != nullptr && !encontrado)
	{
		//Verificar si el dato del nodo actual coincide con el valor a modificar
		if (actual->dato == valorViejo)
		{
			encontrado = true;
		}
		else
		{
			actual = actual->siguiente;
		}
	}
	//Modificar el nodo si fue encontrado
	if (encontrado)
	{
		actual->dato = valorNuevo; //Modificar el dato del nodo
		cout << "El valor " << valorViejo << " ha sido modificado a " << valorNuevo << "." << endl;
	}
	else
	{
		cout << "El valor " << valorViejo << " no fue encontrado en la lista." << endl;
	}
}

#pragma endregion

#pragma region Metodo GuardarEnArchivo

void ListaDoble::GuardarEnArchivo()
{
	ofstream archivo("PromedioNodos.txt");
	if (!archivo) 
	{
		cout << "No se pudo crear el archivo para escribir." << endl;
	}
	archivo << "Datos de la Lista Doble:" << endl;
	NodoDoble* actual = head;
	while (actual != nullptr)
	{
		archivo << actual->dato << endl; //Escribir el dato del nodo actual en el archivo
		actual = actual->siguiente; //Avanzar al siguiente nodo
	}
	archivo.close(); //Cerrar el archivo
}
#pragma endregion

#pragma region Metodo GuardarElPromedio

void ListaDoble::GuardarElPromedio()
{
	ofstream archivo("PromedioNodos.txt", ios::app); //Abrir el archivo en modo append
	if (!archivo) 
	{
		cout << "No se pudo abrir el archivo para escribir." << endl;
	}
	NodoDoble* actual = head;
	float suma = 0;
	int contador = 0;
	//Calcular la suma y el contador de nodos
	while (actual != nullptr)
	{
		suma += actual->dato; //Sumar el dato del nodo actual
		contador++; //Incrementar el contador de nodos
		actual = actual->siguiente; //Avanzar al siguiente nodo
	}
	//Calcular el promedio
	float promedio = (contador > 0) ? static_cast<double>(suma) / contador : 0.0;
	//Escribir el promedio en el archivo
	archivo << "Promedio de los nodos: " << promedio << endl;
	archivo.close(); //Cerrar el archivo
}
#pragma endregion

#pragma region Metodo LeerDesdeArchivo

void ListaDoble::LeerDesdeArchivo()
{
	ifstream archivo("PromedioNodos.txt");
	if (!archivo) 
	{
		cout << "No se pudo abrir el archivo para leer." << endl;
	}
	string linea;
	while (getline(archivo, linea))
	{
		cout << linea << endl; //Mostrar la línea leída del archivo
	}
}
#pragma endregion