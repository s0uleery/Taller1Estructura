#include<iostream>
#pragma once
#include <string>

using namespace std;

class MaterialBibliografico
{
    private:
        string nombre;
        int isbn;
        string autor;
        bool prestado;

    public:

    MaterialBibliografico(string,int,string,bool);
    string getNombre();
    int getIsbn();
    string getAutor();

    void setNombre(string);
    void setIsbn(int);
    void setAutor(string);
    void setPrestado(bool);

    virtual void mostrarInformacion();
    virtual ~MaterialBibliografico();
    //falta el destructor 
    //creo que lo hice bien :P
};
