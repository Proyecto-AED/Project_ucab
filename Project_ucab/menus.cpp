#include <iostream>
#include "menu.h"
using namespace std;

void navegarMantenimiento() {
    int subopcion = -1;

    do {
        system("cls");
        mostrarMenuMantenimiento();
        cin >> subopcion;

        if (subopcion < 0 || subopcion > 8) {
            cout << "\n<Opcion invalida: se esperaba valor entre 0 a 8>\n";
            cout << "<Pulse cualquier tecla para continuar>\n";
            cin.ignore();
            cin.get();
            system("cls");
            continue;
        }

        switch (subopcion) {
        case 1:
            pantallaAgregarPersona();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            cout << "\nFuncionalidad aun no implementada.\n";
            cout << "<Pulse cualquier tecla para continuar>\n";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }

    } while (subopcion != 0);

    system("cls");
}

void mostrarMenuPrincipal() {
    cout << "       ------------------------------------------------------------\n";
    cout << "\tS I S T E M A   D I G I P A G O   M E R C A N C I A L\n";
    cout << "       ------------------------------------------------------------\n";
    cout << "\tRealizado por\n";
    cout << "\tXxxx xxxxxxx  C.I. 99.999.999    Zzzz zzzzzzzz C.I. 99.889.987\n";
    cout << "\tYyyyyy yyyyy  C.I. 98.999.998    Mmmm mmmmmm C.I. 97.987.999\n";
    cout << "       ------------------------------------------------------------\n\n";

    cout << "\tMENU PRINCIPAL\n\n";
    cout << "\t1. MANTENIMIENTO\n";
    cout << "\t2. REALIZAR PAGO\n";
    cout << "\t3. REPORTES\n\n";
    cout << "\t0. Salir\n\n";
    cout << "\tSu opcion: ";
};

void mostrarMenuMantenimiento() {
    cout << "      ------------------------------------------------------------\n";
    cout << "\tS I S T E M A   D I G I P A G O   M E R C A N C I A L\n";
    cout << "      ------------------------------------------------------------\n";
    cout << "\t1 MANTENIMIENTO\n";
    cout << "      ------------------------------------------------------------\n\n";

    cout << "\tPERSONAS\n";
    cout << "\t1 AGREGAR\n";
    cout << "\t2 MODIFICAR TELEFONO\n";
    cout << "\t3 ELIMINAR\n";
    cout << "\t4 BANCOS ASOCIADOS\n";
    cout << "\t5 CONSULTAR POR CEDULA\n";
    cout << "\t6 CONSULTAR POR NOMBRE\n";
    cout << "\t7 MOSTRAR TODAS LAS PERSONAS\n\n";

    cout << "\tBANCOS ALIADOS\n";
    cout << "\t8 ENTIDADES AFILIADAS A DIGIPAGO\n\n";

    cout << "\t0 Salir\n\n";
    cout << "\tSu opcion: ";
};

void pantallaAgregarPersona() {
    system("cls"); // Limpiamos la pantalla antes de mostrar
    cout << "------------------------------------------------------------\n";
    cout << "\tS I S T E M A   D I G I P A G O   M E R C A N C I A L\n";
    cout << "------------------------------------------------------------\n";
    cout << "\t1 1  : AGREGAR persona\n";
    cout << "------------------------------------------------------------\n\n";

    int cedula;
    char nombre[30];
    char telefono[11];
    char confirmar;

    cout << "Indique cedula de identidad: ";
    cin >> cedula;
    cin.ignore(); // Limpiar buffer para leer bien el nombre

    cout << "\nNombre: ";
    cin.getline(nombre, 30);

    cout << "Telefono: ";
    cin.getline(telefono, 11);

    cout << "\nDesea agregar la informacion (S/N)? ";
    //cin >> confirmar;

    /*if (confirmar == 'S' || confirmar == 's') {
        // --- Aquí debería ir la lógica para agregar realmente la persona a la lista ---
        cout << "\n[INFO] Datos guardados (simulado, falta implementar almacenamiento)\n";
    }
    else {
        cout << "\n[INFO] Operacion cancelada por el usuario.\n";
    }

    cout << "\n<Pulse cualquier tecla para volver al menú mantenimiento>\n";
    cin.ignore();
    cin.get();*/
}