#include "Libro.h"
#include <iostream>
#include <string>

using namespace std;

Libro :: Libro(string nombre,int isbn,string autor,bool prestado,string fechaDePublicacion,string resumen) : MaterialBibliografico(nombre,isbn,autor,prestado){
    this -> fechaDePublicacion = fechaDePublicacion;
    this -> resumen = resumen;
}

string Libro :: getFechaDePublicacion(){return fechaDePublicacion;}
string Libro :: getResumen(){return resumen;}

void Libro :: setFechadePublicacion(string fechaDePublicacion){this -> fechaDePublicacion = fechaDePublicacion;}
void Libro :: setResumen(string resumen){this -> resumen = resumen;}

void Libro :: mostrarInformacion(){
    MaterialBibliografico :: mostrarInformacion();
    cout << "Fecha de publicacion: " << fechaDePublicacion << endl;
    cout << "Resumen: " << resumen << endl;
}

Libro :: ~Libro(){
    cout<< "Se elimina el material" << this -> getNombre() << " , " << this -> getIsbn() << endl;
}
