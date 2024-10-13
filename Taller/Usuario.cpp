#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

Usuario :: Usuario(string nombre, int id){
    this -> nombre = nombre;
    this -> id = id;
    
    for (int i = 0; i < 5; ++i) {
        materialBibliografico[i] = nullptr;
    }
}

string Usuario :: getNombre(){return nombre;}
int Usuario :: getId(){return id;}

void Usuario :: setNombre(string nombre){this -> nombre = nombre;}
void Usuario :: setId(int id){this -> id = id;}

Usuario::~Usuario() {
    cout << "Se elimina el usuario " << this->nombre << " , " << this->id << endl;
}

void Usuario :: prestarMaterial(MaterialBibliografico* material){
    bool prestado = false;
    
    for (int i = 0; i < 5; ++i) {
        if (materialBibliografico[i] == nullptr) {
            materialBibliografico[i] = material;
            material->setPrestado(true);
            prestado = true;
            break;
        }
    }

    if (!prestado) {
        cout << "No se puede prestar más materiales. Límite alcanzado (5 materiales)." << endl;
    }
}

void Usuario :: devolverMaterial(MaterialBibliografico* material){
    for (int i = 0; i < 5; ++i) {
        if (materialBibliografico[i] == material) {
            materialBibliografico[i] = nullptr;
            material->setPrestado(false);
            return;
        }
    }
    cout << "Material no encontrado entre los prestados." << endl; 
}

void Usuario :: mostrarMaterialesPrestados(){
    cout << "Materiales prestados a " << nombre << " (ID: " << id << "):" << endl;
    bool tieneMateriales = false;
    
    for (int i = 0; i < 5; ++i) {
        if (materialBibliografico[i] != nullptr) {
            materialBibliografico[i]->mostrarInformacion();
            tieneMateriales = true;
        }
    }
    if (!tieneMateriales) {
        cout << nombre << " no tiene materiales prestados." << endl;
    }
}
