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
        Libro(nombre,isbn,autor,prestado,fechaDePublicacion,resumen);

        string getFechaDePublicacion();
        string getResumen();

        void setFechadePublicacion(string);
        void setResumen(string);

        void mostrarInformacion();
        virtual ~Libro();
}