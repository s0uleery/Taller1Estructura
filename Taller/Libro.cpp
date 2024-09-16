#include "Libro.h"
#include <iostream>
#include <string>

Libro :: Libro(nombre,isbn,autor,prestado,fechaDePublicacion,resumen){
    this -> fechaDePublicacion = fechaDePublicacion;
    this -> resumen = resumen;
}

string Libro :: getFechaDePublicacion(){return fechaDePublicacion;}
string Libro :: getResumen(){return resumen;}

void Libro :: setFechadePublicacion(string fechaDePublicacion){this -> fechaDePublicacion = fechaDePublicacion;}
void Libro :: setResumen(string resumen){this -> resumen = resumen;}

void Libro :: mostrarInformacion(){
    MaterialBibliografico :: mostrarInformacion();
}

Libro :: ~Libro(){
    cout<< "Se elimina el material" << this -> nombre << " , " << this -> isbn << endl;
}