#include <iostream>

class MaterialBibliografico
{
    private:
        std::string "nombre";
        int isbn;
        std::string "autor";
        bool prestado;

    public:
    MaterialBibliografico();
    virtual mostrarInformacion();
    //falta el destructor
}