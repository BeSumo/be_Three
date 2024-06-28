#include "hash.h"
#include <iostream>
#include <stdexcept>

using namespace std;

registro_cuentas::registro_cuentas() {
    tabla = new cuenta[ranuras]();
}

registro_cuentas::~registro_cuentas() {
    delete[] tabla;
}

int registro_cuentas::hash(string rol) { // MODIFICAR SI QUIERES LA FORMULA HASH VALUE
    int hash_value = 0;
    for (char c : rol) {
        hash_value = (hash_value * 31 + c) % ranuras;
    }
    return hash_value;
}


int registro_cuentas::p(string rol, int i) {
    return (hash(rol) + i) % ranuras;
}

/*
cuenta registro_cuentas::obtener(string rol) {
    int i = 0;
    int index;
    do {
        index = p(rol, i);
        if (tabla[index].rol == rol && tabla[index].activo) {
            return tabla[index];
        }
        i++;
    } while (tabla[index].activo && i < ranuras);
    throw invalid_argument("Rol no existente");
}
*/

// RECORDAR VER LA DESCRIPCION DE LA TAREA
void registro_cuentas::agregar(cuenta c) {
    int i = 0;
    int index = hash(c.rol)%ranuras;
    // AQUI CONDICION COLISION
    if (tabla[index].nombre == ""){
        tabla[index] = c; // AGREGADO EN CASO DE QUE ESTE LIBRE
        cout<< tabla[index].nombre << endl;
    }
    else{
        // AQUI HAY COLISION
        // AQUI NECESITAMOS UN CONTANDOR EN CASO DE QUE EL SIGUIENTE ESPACIO ESTE OCUPADO
        bool found=false;
        while(!found){
            int pos = p(c.rol,i);
            if(tabla[pos].nombre ==""){
                found = true;
                tabla[pos] = c;
                cout<< tabla[pos].nombre<<endl;
            }
            i++;  
        }
    }
}


// RECORDAR VER LA DESCRIPCION DE LA TAREA
void registro_cuentas::eliminar(string rol){
    int i = 0;
    int index = hash(rol)%ranuras;
    //AQUI VA ESTAR LA 1ERA CONDICION (QUE LO ENCONTREMOS ALTIRO)
    //PARA COMPARAR HABRA QUE ACCEDER AL ROL
    if (tabla[index].rol==rol){
        tabla[index].nombre= "";
        tabla[index].descripcion = "";
        tabla[index].rol= "";
        // AQUI HAY QUE AGREGAR UN CONTANDOR DE ELIMINACION
    }
    else {
        bool found = false;
        while(!found){
            int pos = p(rol,i);
            if(tabla[pos].rol==rol){
                tabla[index].nombre= "";
                tabla[index].descripcion = "";
                tabla[index].rol= "";
            }
        }
    }

}
/*

void registro_cuentas::eliminar(string rol) {
    int i = 0;
    int index;
    do {
        index = p(rol, i);
        if (tabla[index].rol == rol && tabla[index].activo) {
            tabla[index].activo = false;
            ocupadas--;
            factor_de_carga = static_cast<float>(ocupadas) / ranuras;
            return;
        }
        i++;
    } while (tabla[index].activo && i < ranuras);
    cout << "Rol no existente" << endl;
}

void registro_cuentas::modificar(string rol, string descripcion) {
    int i = 0;
    int index;
    do {
        index = p(rol, i);
        if (tabla[index].rol == rol && tabla[index].activo) {
            tabla[index].descripcion = descripcion;
            return;
        }
        i++;
    } while (tabla[index].activo && i < ranuras);
    cout << "Rol no existente" << endl;
}

void registro_cuentas::redimensionar(int nuevo_tamano) {
    cuenta* nueva_tabla = new cuenta[nuevo_tamano]();
    int viejo_tamano = ranuras;
    ranuras = nuevo_tamano;
    ocupadas = 0;

    for (int i = 0; i < viejo_tamano; ++i) {
        if (tabla[i].activo) {
            agregar(tabla[i]);
        }
    }

    delete[] tabla;
    tabla = nueva_tabla;
}


void registro_cuentas::estadisticas() {
    cout << "RANURAS OCUPADAS: " << ocupadas << endl;
    cout << "RANURAS TOTALES: " << ranuras << endl;
    cout << "FACTOR DE CARGA: " << factor_de_carga << endl;
}*/