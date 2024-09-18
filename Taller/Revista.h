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
        Revista(string,int, string, bool,int,string);

        int getNumeroEdicion();
        string getMesPublicacion();

        void setNumeroEdicion(int);
        void setMesPublicacion(string);
        
        void mostrarInformacion();
        virtual ~Revista(); //no estoy segura

};
