#include "Biblioteca.h"
#include <iostream>
#include <string>

using namespace std;

Biblioteca :: Biblioteca(){
    this -> cantidadMateriales = 0;
    for (int i = 0; i < 100; ++i) {
        biblioteca[i] = nullptr;
    }
}

void Biblioteca :: agregarMaterial(MaterialBibliografico* material){
   if(cantidadMateriales < 100){
        biblioteca[cantidadMateriales++] = material;
   }else{
        cout <<"La biblioteca esta llena" << endl;
   }
}

void Biblioteca :: mostrarMaterial(){
    for (int i = 0; i < cantidadMateriales; ++i) {
            biblioteca[i]->mostrarInformacion();
    }
}      

MaterialBibliografico* Biblioteca :: buscarMaterial(string buscador){
    for (int i = 0; i < cantidadMateriales; ++i) {
        if(biblioteca[i] -> getNombre() == buscador || biblioteca[i] -> getAutor() == buscador){
                return biblioteca[i];
            }
        }
        return nullptr;
}
        
Biblioteca :: ~Biblioteca() {
    for (int i = 0; i < 100; ++i) {
        delete biblioteca[i];
    }
}
