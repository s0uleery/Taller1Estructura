#include <iostream>

using namespace System;
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

int main() {

    int op;

    do{
         menu();
         cin >> op;

        switch(op){
            case 1:
            cout << ": )" << endl;
            break;

            case 2:
            cout << ":p" << endl;
            break;

            case 3:
            cout << ":3" << endl;
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
    System("cls");

    }while(op != 0 );

    cout << "Salio del programa " << endl;

    return 0;
}
