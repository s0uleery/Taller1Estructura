#include<iostream>
#pragma once
#include <string>
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico
{
    private:
        string fechaDePublicacion;
        string resumen;

    public:
        Libro(string,int, string, bool,string,string);

        string getFechaDePublicacion();
        string getResumen();

        void setFechadePublicacion(string);
        void setResumen(string);

        void mostrarInformacion();
        virtual ~Libro();
};
