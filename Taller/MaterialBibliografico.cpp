#include "MaterialBibliografico.h"
#include <iostream>
#include <string>

using namespace std;

MaterialBibliografico :: MaterialBibliografico(string nombre,int isbn, string autor, bool prestado) {
        this -> nombre = nombre;
        this -> isbn = isbn;
        this -> autor = autor;
        this -> prestado = false;
};

string MaterialBibliografico :: getNombre(){return nombre;}
int MaterialBibliografico :: getIsbn(){return isbn;}
string MaterialBibliografico :: getAutor(){return autor;}

void MaterialBibliografico :: setNombre(string nombre){this -> nombre = nombre;}
void MaterialBibliografico :: setIsbn(int isbn){this -> isbn = isbn;}
void MaterialBibliografico :: setAutor(string autor){this -> autor = autor;}
void MaterialBibliografico :: setPrestado(bool prestado){this -> prestado = prestado;}

void MaterialBibliografico :: mostrarInformacion(){};

MaterialBibliografico :: ~MaterialBibliografico(){
    cout<< "Se elimina el material" << this -> nombre << " , " << this -> isbn << endl;
    //creo que esta bien hecho :P
};
