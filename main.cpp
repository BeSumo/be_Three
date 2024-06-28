
#include "hash.h"
#include <iostream>

using namespace std;

int main() {
    registro_cuentas registro;
    cuenta c1 = {"2021305053", "Benjamin Cespedes", "Estudiante de Ingeniería Civil", true};
    registro.agregar(c1); //agrega a la tabla hashing la cuenta parámetro.
    registro.hash("202130553");
    int i = 0;
    while(i<15){
        cout<< registro.p("202130553",i)<<endl;
        i++;
    }
    /*
    registro.estadisticas();
    registro.agregar(c1);
    cout << "------------" << endl;
    registro.estadisticas();

    cuenta cuentaConsultada = registro.obtener("2021305053");
    cout << cuentaConsultada.nombre << ": " << cuentaConsultada.descripcion << endl;
    
    cuenta c2 = {"2021405053", "Benjamin Cesp", " de Ingeniería Civil", true};
    cuenta c3 = {"2021505053", "Benjamin Cespes", "Estudiante  Ingeniería Civil", true};
    cuenta c4 = {"2021805053", "Benjamin Ceedes", "Estudiante de  Civil", true};
    cuenta c5 = {"2021165053", "Benjamin Cpedes", " de Ingeniería Civil", true};
    cuenta c6 = {"2021345053", "Benjamin espedes", "Estudiante de  ", true};

    registro.agregar(c3);
    registro.agregar(c3);
    registro.agregar(c4);
    registro.agregar(c5);
    registro.agregar(c6);

    //registro.eliminar("20201002");
    registro.estadisticas();
    */
    
    return 0;
}
