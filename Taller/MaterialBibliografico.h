#include <iostream>

class MaterialBibliografico
{
    private:
        string nombre;
        int isbn;
        string autor;
        boolean prestado;

    public:
    MaterialBibliografico();
    virtual mostrarInformacion();
    //falta el destructor
}