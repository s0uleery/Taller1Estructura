#include <iostream>
#include <string>

class Usuario
{
private:
    string nombre;
    int id;
    string materialBibliografico[5];

public:
    Usuario(string nombre, int id);
    void prestarMaterial;
    void devolverMateral;
    void mostrarMaterialesPrestados;
}
