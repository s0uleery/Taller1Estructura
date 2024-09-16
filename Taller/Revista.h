#include<iostream>
#pragma once
#include <string>
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico
{
    private:
        int numeroEdicion;
        string mesPublicacion;

    public:
        Revista(nombre,isbn,autor,prestado,numeroEdicion,mesPublicacion);

        string getNumeroEdicion();
        string getMesPublicacion();

        void setNumeroEdicion(string);
        void setMesPublicacion(string);
        
        void mostrarInformacion();
        virtual ~Revista(); //no estoy segura

}