#include<iostream>
#pragma once
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario {
private:
    string nombre;
    int id;
    MaterialBibliografico* materialBibliografico[5]; 

public:
    Usuario(string, int);
    string getNombre();
    int getId();

    void setNombre(string);
    void setId(int);

    void prestarMaterial(MaterialBibliografico*);
    void devolverMateral(MaterialBibliografico*);
    void mostrarMaterialesPrestados();
    ~Usuario();
};
