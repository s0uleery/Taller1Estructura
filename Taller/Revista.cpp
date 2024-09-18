#include "Revista.h"
#include <iostream>
#include <string>

using namespace std;

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
    cout << "Numero de edicion: " << fechaDePublicacion << endl;
    cout << "Mes de publicacion: " << mesPublicacion << endl;
}

Revista :: ~Revista(){
    cout<< "Se elimina el material" << this -> nombre << " , " << this -> isbn << endl;
}
