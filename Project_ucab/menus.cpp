#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
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
            pantallaModificarTelefono();
            break;
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
    cout << "\tJohendry Zambrano  C.I. 30.991.103    Zzzz zzzzzzzz C.I. 99.889.987\n";
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
    system("cls"); 
    cout << "      ------------------------------------------------------------\n";
    cout << "\tS I S T E M A   D I G I P A G O   M E R C A N C I A L\n";
    cout << "      ------------------------------------------------------------\n";
    cout << "\t1.1  : Agregar persona\n";
    cout << "      ------------------------------------------------------------\n\n";

    int cedula;
    char nombre[30];
    char telefono[13];
    char confirmar;

    cout << "Indique cedula de identidad: ";
    cin >> cedula;
    cin.ignore();

    cout << "\nNombre y Apellido (sin espacios o usa _): ";
    cin.getline(nombre, 30);

    cout << "Telefono: ";
    cin.getline(telefono, 13);

    FILE* archivo = fopen("data/personas.txt", "r");
    int cedulaExistente;
    char nombreTemp[30];
    char telefonoTemp[13];
    bool existe = false;

    if (archivo != NULL) {
        while (fscanf(archivo, "%d %s %s", &cedulaExistente, nombreTemp, telefonoTemp) != EOF) {
            if (cedulaExistente == cedula) {
                existe = true;
                break;
            }
        }
        fclose(archivo);
    }

    if (existe) {
        cout << "\n[ERROR] Cedula ya registrada.\n";
    }
    else {
        cout << "\nDesea agregar la informacion (S/N)? ";
        cin >> confirmar;

        if (confirmar == 'S' || confirmar == 's') {
            FILE* out = fopen("data/personas.txt", "a");
            if (out != NULL) {
                fprintf(out, "%d %s %s\n", cedula, nombre, telefono);
                fclose(out);
                cout << "\n[INFO] Datos guardados exitosamente.\n";
            }
            else {
                cout << "\n[ERROR] No se pudo abrir el archivo para guardar.\n";
            }
        }
        else {
            cout << "\n[INFO] Operacion cancelada por el usuario.\n";
        }
    }

    cout << "\n<Pulse cualquier tecla para volver al menu mantenimiento>\n";
    cin.ignore();
    cin.get();
}

void pantallaModificarTelefono() {
    system("cls");
    cout << "      ------------------------------------------------------------\n";
    cout << "\tS I S T E M A   D I G I P A G O   M E R C A N C I A L\n";
    cout << "      ------------------------------------------------------------\n";
    cout << "\t1.2  : MODIFICAR teléfono\n";
    cout << "      ------------------------------------------------------------\n\n";

    int cedulaBuscada;
    int cedulaLeida;
    char nombreTemp[30], telefonoTemp[13];
    char nuevoTelefono[13];
    char confirmar;
    bool encontrado = false;

    cout << "Indique cedula de identidad: ";
    cin >> cedulaBuscada;

    FILE* archivo = fopen("data/personas.txt", "r");
    FILE* temporal = fopen("data/temp.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        cout << "\n[ERROR] No se pudo abrir el archivo.\n";
        return;
    }

    while (fscanf(archivo, "%d %s %s", &cedulaLeida, nombreTemp, telefonoTemp) != EOF) {
        if (!encontrado && cedulaLeida == cedulaBuscada) {
            encontrado = true;
            cout << "\nNombre: " << nombreTemp;
            cout << "\nTelefono actual: " << telefonoTemp;

            cout << "\n\nNuevo numero = ";
            cin.ignore();
            cin.getline(nuevoTelefono, 13);

            cout << "\nConfirma el nuevo numero (S/N)? ";
            cin >> confirmar;

            if (confirmar == 'S' || confirmar == 's') {
                fprintf(temporal, "%d %s %s\n", cedulaLeida, nombreTemp, nuevoTelefono);
                cout << "\n[INFO] Telefono actualizado.\n";
            }
            else {
                fprintf(temporal, "%d %s %s\n", cedulaLeida, nombreTemp, telefonoTemp);
                cout << "\n[INFO] Operacion cancelada, se mantiene el numero original.\n";
            }
        }
        else {
            fprintf(temporal, "%d %s %s\n", cedulaLeida, nombreTemp, telefonoTemp);
        }
    }

    fclose(archivo);
    fclose(temporal);

    remove("data/personas.txt");
    rename("data/temp.txt", "data/personas.txt");

    if (!encontrado) {
        cout << "\n[ERROR] Cedula no encontrada.\n";
    }

    cout << "\n<Pulse cualquier tecla para volver al menu de mantenimiento>\n";
    cin.ignore();
    cin.get();
}

