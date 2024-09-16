#include<iostream>
#pragma once
#include <string>

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"

using namespace std;

class Biblioteca{
    private: 
        MaterialBibliografico* biblioteca[100];
        int cantidadMateriales;

    public:
        Biblioteca();
        void agregarMaterial(MaterialBibliografico*);
        MaterialBibliografico* mostrarMaterial();
        MaterialBibliografico* buscarMaterial(string);
        ~Biblioteca();
};


