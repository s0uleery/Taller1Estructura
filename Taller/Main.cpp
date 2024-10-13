#include "Biblioteca.h"
#include "Usuario.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>
#include <fstream>

using namespace std;

void menu(){
    cout << "--------------------------------------------------------" << endl;
    cout << "Biblioteca Digital" << endl;
    cout << "1. Agregar Material a la Biblioteca" << endl;
    cout << "2. Mostrar Información de los Materiales" << endl;
    cout << "3. Buscar Material" << endl;
    cout << "4. Prestar o Devolver Material" << endl;
    cout << "5. Gestión de Usuarios(crear, buscar o eliminar usuario)" << endl;
    cout << "0. SALIR " << endl;
    cout << "Seleccione una opción: " << endl;
    cout << "--------------------------------------------------------" << endl;

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
        convertirMinusculas(nombre);
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Autor: ";
        cin >> autor;
        convertirMinusculas(autor);
        cout << "Fecha de Publicación: ";
        cin >> fechaPublicacion;
        convertirMinusculas(fechaPublicacion);
        cout << "Resumen: ";
        cin >> resumen;
        convertirMinusculas(resumen);
        biblioteca.agregarMaterial(new Libro(nombre, isbn, autor, false, fechaPublicacion, resumen));
    }
    else if(tipo == "revista"){
        string mesPublicacion;
        int numeroEdicion;
        cout << "Nombre: ";
        cin >> nombre;
        convertirMinusculas(nombre);
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Autor: ";
        cin >> autor;
        convertirMinusculas(autor);
        cout << "Número de Edición: ";
        cin >> numeroEdicion;
        cout << "Mes de Publicación: ";
        cin >> mesPublicacion;
        convertirMinusculas(mesPublicacion);
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

void prestarDevolver(Usuario& usuario,Biblioteca& biblioteca){
    string respuesta;
    string nombreT;
    cout << "Que desea hacer prestar o devolver: ";
    cin >> respuesta;
    convertirMinusculas(respuesta);
    
    cout << "Ingrese nombre del texto: ";
    cin.ignore();
    getline(cin, nombreT);
    convertirMinusculas(nombreT);
    
    if (respuesta == "prestar") {
        MaterialBibliografico* material = biblioteca.buscarMaterial(nombreT);
        if (material != nullptr) {
            usuario.prestarMaterial(material);
            usuario.mostrarMaterialesPrestados();
        } else {
            cout << "Material no encontrado." << endl;
        }
    } else if (respuesta == "devolver") {
        MaterialBibliografico* material = biblioteca.buscarMaterial(nombreT);
        if (material != nullptr) {
            usuario.devolverMaterial(material);
            cout << "Material devuelto correctamente." << endl;
        } else {
            cout << "Material no encontrado." << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }
}

void punto4(Biblioteca& biblioteca){
    string nombre;
    int id;
    
    cout << "Ingrese su nombre (nombre, apellido con espacios y minúsculas): ";
    cin.ignore();
    getline(cin, nombre);
    convertirMinusculas(nombre);

    cout << "Ingrese su rut (sin puntos ni guion): ";
    cin >> id;
    
    Usuario* encontrado = biblioteca.buscarUsuario(nombre, id);
    
    if (encontrado != nullptr) {
        prestarDevolver(*encontrado, biblioteca);
    } else {
        cout << "Usuario no encontrado o datos incorrectos." << endl;
    }
}
    
void gestionUsuarios(Biblioteca& biblioteca){
    int op;
    cout << "1. Crear Usuario" << endl;
    cout << "2. Buscar Usuario" << endl;
    cout << "3. Eliminar Usuario" << endl;
    cout << "Seleccione una opción: ";
    cin >> op;

    string nombre;
    int id;

    switch(op) {
        case 1: {
            cout << "Ingrese su nombre (nombre, apellido con espacios y minúsculas): ";
            cin.ignore();
            getline(cin, nombre);
            convertirMinusculas(nombre);

            cout << "Ingrese su rut (sin puntos ni guion): ";
            cin >> id;

            biblioteca.agregarUsuario(new Usuario(nombre, id));
            cout << "Usuario creado exitosamente." << endl;
            break;
        }
        case 2: {
            cout << "Ingrese su nombre (nombre, apellido con espacios y minúsculas): ";
            cin.ignore();
            getline(cin, nombre);
            convertirMinusculas(nombre);

            cout << "Ingrese su rut (sin puntos ni guion): ";
            cin >> id;

            Usuario* encontrado = biblioteca.buscarUsuario(nombre, id);
            if (encontrado != nullptr) {
                encontrado->mostrarMaterialesPrestados();
            } else {
                cout << "Usuario no encontrado o datos incorrectos." << endl;
            }
            break;
        }
        case 3: {
            cout << "Ingrese su nombre (nombre, apellido con espacios y minúsculas): ";
            cin.ignore();
            getline(cin, nombre);
            convertirMinusculas(nombre);

            cout << "Ingrese su rut (sin puntos ni guion): ";
            cin >> id;

            if (biblioteca.eliminarUsuario(nombre, id)) {
                cout << "...." << endl;
            } else {
                cout << "Error: Usuario no encontrado." << endl;
            }
            break;
        }
        default: {
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    }
}
    
int main() {

    Biblioteca biblioteca;
    biblioteca.agregarMaterial(new Libro("papelucho", 123456, "marcela paz", false, "1/12/1947", "papelucho, se trata de su diario de vida donde relata el mundo visto desde sus ojos de niño, contando sus vivencias y anécdotas"));
    biblioteca.agregarMaterial(new Revista("rolling stone", 456789, "jann wenner", false, 789, "junio"));
    biblioteca.agregarUsuario(new Usuario("juan perez", 1234));

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
            punto4(biblioteca);
            break;

            case 5:
            gestionUsuarios(biblioteca);
            break;

            case 0:
            cout << "Esta saliendo del programa..." << endl;
            break;

            default:
            cout << "Opción no válida..." << endl;
            break;
        } 

    }while(op != 0 );
    return 0;
}
