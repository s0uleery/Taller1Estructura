#include "Biblioteca.h"
#include <iostream>
#include <string>

using namespace std;

Biblioteca :: Biblioteca(){
    this -> cantidadMateriales = 0;
    for (int i = 0; i < 100; ++i) {
        biblioteca[i] = nullptr;
    }
    
    cantidadUsuarios = 0;
        for (int i = 0; i < 100; ++i) {
        usuarios[i] = nullptr;
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
    if(cantidadMateriales == 0){
        cout <<"La biblioteca esta vacia" << endl;
    }else{
        for (int i = 0; i < cantidadMateriales; ++i) {
        biblioteca[i]->mostrarInformacion();
        }
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

Usuario* Biblioteca::buscarUsuario(string nombre, int id) {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i] != nullptr && usuarios[i]->getNombre() == nombre && usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

bool Biblioteca::eliminarUsuario(string nombre, int id) {
    for (int i = 0; i < cantidadUsuarios; ++i) {
        if (usuarios[i] != nullptr && usuarios[i]->getNombre() == nombre && usuarios[i]->getId() == id) {
            delete usuarios[i];
            usuarios[i] = nullptr;
            cout << "Usuario " << nombre << " eliminado correctamente." << endl;
            return true;
        }
    }
    cout << "Usuario no encontrado." << endl;
    return false;
}

void Biblioteca::agregarUsuario(Usuario* usuario) {
    if (cantidadUsuarios < 100) {
        usuarios[cantidadUsuarios++] = usuario;
    } else {
        cout << "No se pueden agregar más usuarios. Capacidad completa." << endl;
    }
}

        
Biblioteca :: ~Biblioteca() {
    for (int i = 0; i < 100; ++i) {
        delete biblioteca[i];
    }
}
