#include<iostream>
#pragma once
#include <string>

#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

using namespace std;

class Biblioteca{
    private: 
        MaterialBibliografico* biblioteca[100];
        int cantidadMateriales;
        
        Usuario* usuarios[100];
        int cantidadUsuarios;   

    public:
        Biblioteca();
        void agregarMaterial(MaterialBibliografico*);
        void mostrarMaterial();
        MaterialBibliografico* buscarMaterial(string);
        
        Usuario* buscarUsuario(string nombre, int id); 
        bool eliminarUsuario(string nombre, int id);   
        void agregarUsuario(Usuario* usuario);
        
        ~Biblioteca();
};
