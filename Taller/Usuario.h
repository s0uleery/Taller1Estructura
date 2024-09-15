#include <iostream>

class Usuario
{
    private:
        std::string 'nombre';
        int id;
        std::string materialBibliografico[5];

    public:
        Usuario(string nombre, int id);
        void prestarMaterial();
        void devolverMateral();
        void mostrarMaterialesPrestados();
        //falta el destructor
}
