#include "Revista.h"
#include <iostream>
#include <string>

using namespace std;

Revista::Revista(string nombre, int isbn, string autor, bool prestado, int numeroEdicion, string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado) {
    this->numeroEdicion = numeroEdicion;
    this->mesPublicacion = mesPublicacion;
}

int Revista::getNumeroEdicion() { return numeroEdicion; }
string Revista::getMesPublicacion() { return mesPublicacion; }

void Revista::setNumeroEdicion(int numeroEdicion) { this->numeroEdicion = numeroEdicion; }
void Revista::setMesPublicacion(string mesPublicacion) { this->mesPublicacion = mesPublicacion; }

void Revista::mostrarInformacion() {
    MaterialBibliografico::mostrarInformacion();
    cout << "Numero de edicion: " << numeroEdicion << endl;
    cout << "Mes de publicacion: " << mesPublicacion << endl;
}

Revista::~Revista() {
    cout << "Se elimina el material " << this->getNombre() << " , " << this->getIsbn() << endl;
}
