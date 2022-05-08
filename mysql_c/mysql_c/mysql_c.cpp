#include <iostream>
#include <mysql.h>
#include <string>
#include "Estudiante.h"
#include "ConexionBD.h"
using namespace std;

void mostrarMenu() {
    cout << "-----------------Bienvenido al Registro de Estudiantes-----------------" << endl;
    cout << "1. Ingresar Estudiantes" << endl;
    cout << "2. Ver Estudiantes" << endl;
    cout << "3. Actualizar Estudiantes" << endl;
    cout << "4. Eliminar Estudiantes" << endl;
    cout << "5. Salir" << endl << endl;
    cout << "Inserte el numero de la accion a realizar: ";
}

int main()
{
    char repetir;
    int op;

    do
    {
        system("cls");
        mostrarMenu();
        cin >> op;
        cin.ignore();
        system("cls");
        Estudiante estudiante = Estudiante();
        switch (op)
        {
        case 1:
        {
            string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
            int telefono, genero;
            cout << "----------- Insertar estudiante ----------" << endl << endl;
            cout << "Ingrese el carnet: ";
            getline(cin, carnet);
            cout << "Ingrese nombres: ";
            getline(cin, nombres);
            cout << "Ingrese apellidos: ";
            getline(cin, apellidos);
            cout << "Ingrese direccion: ";
            getline(cin, direccion);
            cout << "Ingrese telefono: ";
            cin >> telefono;
            cin.ignore();
            cout << "Ingrese genero: ";
            cin >> genero;
            cin.ignore();
            cout << "Ingrese email: ";
            getline(cin, email);
            cout << "Fecha de nacimiento: ";
            getline(cin, fecha_nacimiento);
            fflush(stdin);


            Estudiante(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
            estudiante.crear();
            system("pause");
            cout << endl; 

        }
        break;
        case 2:
        {
            cout << "---------- Registro de Estudiantes ----------" << endl << endl;
            estudiante.leer();
            cout << endl << endl;
        }
        break;
        case 3:
        {
            string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
            int telefono, genero, id;
            cout << "---------- Registro de Estudiantes ----------" << endl << endl;
            estudiante.leer();
            cout << endl << endl << endl;

            cout << "---------- Actualizar estudiante ----------" << endl << endl;
            cout << "Ingrese el ID del estudiante que desea modificar:  " << endl;
            cin >> id;
            cin.ignore();
            cout << endl;
            cout << "Ingrese el carnet: ";
            getline(cin, carnet);
            cout << "Ingrese el/los nombres: ";
            getline(cin, nombres);
            cout << "Ingrese el apellido: ";
            getline(cin, apellidos);
            cout << "Ingrese la direccion: ";
            getline(cin, direccion);
            cout << "Ingrese telefono: ";
            cin >> telefono;
            cin.ignore();
            cout << "Ingrese genero: ";
            cin >> genero;
            cin.ignore();
            cout << "Ingrese email: ";
            getline(cin, email);
            cout << "Fecha de nacimiento(YYYY-MM-DD): ";
            getline(cin, fecha_nacimiento);
            fflush(stdin);
            Estudiante(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento);
            estudiante.actualizar(id); 
            system("pause");
            cout << endl;

        }
        break;
        case 4:
        {
            cout << "------------ Datos de Estudiantes ------------" << endl << endl;
            estudiante.leer();
            cout << endl << endl << endl;

            int id;
            cout << "------------ Eliminar del registro al estudiante ------------" << endl << endl;
            cout << "Ingrese el ID del estudiante que desea eliminar:  " << endl;
            cin >> id;
            cin.ignore();
            estudiante.borrar(id);
            system("pause");
        }
        break;
        case 5:
        {
            break;
        }
        break;
        default:
            cout << "La opcion escogina no existe";
        }

        if (op == 5) {
            break;
        }

        cout << "********************************************" << endl;
        cout << "Desea realizar otra accion s/n" << endl;
        cin >> repetir;
        repetir = tolower(repetir);
        estudiante.~Estudiante();
    } while (repetir == 's');
    cout << endl << "Fue un placer atenderle, tenga buen dia" << endl;

}