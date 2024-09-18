#include "Biblioteca.h"
#include "Usuario.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>

using namespace std;

void menu(){
    cout << "Biblioteca Digital Sim" << endl;
    cout << "1. Agregar Material a la Biblioteca" << endl;
    cout << "2. Mostrar Información de los Materiales" << endl;
    cout << "3. Buscar Material" << endl;
    cout << "4. Prestar y Devolver Material" << endl;
    cout << "5. Gestión de Usuarios" << endl;
    cout << "0. SALIR " << endl;
    cout << "Seleccione una opción: " << endl;

}

void convertirMinusculas(string &str) {
    for (char &c : str) {
        c = tolower(c); 
    }
}  

void agregar(Biblioteca& biblioteca){
    string tipo;
    string nombre, autor;
    int isbn;
    cout << "Seleccione tipo de material (Libro o Revista): " << endl;
    cin >> tipo; 
    
    convertirMinusculas(tipo);
    
    if(tipo == "libro"){
        string fechaPublicacion, resumen;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Autor: ";
        cin >> autor;
        cout << "Fecha de Publicación: ";
        cin >> fechaPublicacion;
        cout << "Resumen: ";
        cin >> resumen;
        biblioteca.agregarMaterial(new Libro(nombre, isbn, autor, false, fechaPublicacion, resumen));
    }
    else if(tipo == "revista"){
        
        string mesPublicacion;
        int numeroEdicion;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Autor: ";
        cin >> autor;
        cout << "Número de Edición: ";
        cin >> numeroEdicion;
        cout << "Mes de Publicación: ";
        cin >> mesPublicacion;
        biblioteca.agregarMaterial(new Revista(nombre, isbn, autor, false, numeroEdicion, mesPublicacion));
    }else{
        cout << "Tipo de material no válido. Por favor, ingrese 'Libro' o 'Revista'." << endl;
    }
}
    
void buscarMaterial(Biblioteca& biblioteca){
    string dato;
    cout<< " Ingrese el nombre del material o su autor:"<< endl;
    cin >> dato;
    convertirMinusculas(dato);
    
    MaterialBibliografico* a = biblioteca.buscarMaterial(dato);
    
    if(a != nullptr){
       a->mostrarInformacion();
    }else{
        cout << "Material no encontrado" << endl;
    }
}
    
int main() {

    Biblioteca biblioteca;
    Usuario usuario1("Juan Perez", 1);
    
    int op;

    do{
         menu();
         cin >> op;

        switch(op){
            case 1:
            agregar(biblioteca);
            break;
            case 2:
            biblioteca.mostrarMaterial();
            break;

            case 3:
            buscarMaterial(biblioteca);
            break;

            case 4:
            cout << ":o" << endl;
            break;

            case 5:
            cout << ":()" << endl;
            break;

            case 0:
            cout << "Esta saliendo del programa..." << endl;
            break;

            default:
            cout << "Opcion no valida " << endl;
            break;
        } 

    }while(op != 0 );

    cout << "Salio del programa " << endl;

    return 0;
}
