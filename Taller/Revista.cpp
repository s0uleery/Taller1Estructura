#include "Revista.h"
#include <iostream>
#include <string>

Revista :: Revista(nombre,isbn,autor,prestado,numeroEdicion,mesPublicacion){
    this -> numeroEdicion = numeroEdicion;
    this -> mesPublicacion = mesPublicacion;
}

string Revista :: getNumeroEdicion(){return numeroEdicion;}
string Revista :: getMesPublicacion(){return mesPublicacion;}

void Revista :: setNumeroEdicion(string numeroEdicion){this -> numeroEdicion = numeroEdicion;}
void Revista :: setMesPublicacion(string mesPublicacion){this -> mesPublicacion = mesPublicacion;}

void Revista :: mostrarInformacion(){
    MaterialBibliografico :: mostrarInformacion();
}

Revista :: ~Revista(){
    cout<< "Se elimina el material" << this -> nombre << " , " << this -> isbn << endl;
}
