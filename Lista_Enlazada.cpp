
#include <iostream>

using namespace std;

struct Nodo{
	int dato;
	Nodo*siguiente;
	};

Nodo* NuevoNodo(Nodo*inicio,int elemento){
	
	Nodo* nuevo = new Nodo; //aqui agarramos la direccion del nuevo nodo
	nuevo->dato = elemento;
	nuevo->siguiente = inicio; 
	return nuevo;
	
	}

int main(){
	
	//Codigo de una lista enlazada
	
	Nodo* inicio = nullptr; cout<<inicio<<endl;// tengo entendido que la direcion del nodo inicio seria 0 poniendolo en el primero de la cola
	cout<<* inicio<<endl;
	int contador = 1;
	int n;cout<<"Ingrese su numero(Finalizar con 0)"<<endl; cin >> n; // aqui agarramos el dato que queramos colocar 
	
	while (n!=0){
		
		inicio = NuevoNodo(inicio, n );
		cout<<inicio<<" Esta es la direcion de memoria del nodo "<<contador<<endl;
		cin>>n;
		++contador;
		}
	return 0;
	
}

// ver si funciona correctamente, pq no aparece la primera direccion como 0, lo cual es raro, ver el tema de los delete, y  hacer funcion  para mostrar los nodos
// Algo raro hice la verdad, cuidado a
