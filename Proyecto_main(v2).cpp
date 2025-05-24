#include <iostream>
#include "menu(v2).h"
using namespace std;

int main() {
    int opcion = -1;
    DGper * lista = cargar_lista_desde_archivo("personas.txt");
    muestralista(lista, 'L');
    DGbancos * lista2 = cargar_lista_desde_archivo_bancos("bancos.txt");
    muestralista2(lista2, 'B');

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        if (opcion < 0 || opcion > 3) {
            cout << "\n<Opcion invalida: se esperaba valor entre 0 a 3>\n";
            cout << "<Pulse cualquier tecla para continuar>\n";
            cin.ignore();
            cin.get();
            system("cls");
            continue;
        }

        switch (opcion) {
        case 1: { // hace la navegacion de la pantalla principal a mantenimeinto
            navegarMantenimiento();
            break;
        }
        case 2:
            cout << "\nREALIZAR PAGO aun no esta disponible.\n";
            break;
        case 3:
            cout << "\nREPORTES aun no est� disponible.\n";
            break;
        case 0:
            cout << "\nSaliendo del sistema...\n";
            break;
        }

        if (opcion != 0) {
            cout << "\n<Pulse cualquier tecla para continuar>\n";
            cin.ignore();
            cin.get();
            system("cls");
        }

    } while (opcion != 0);

    return 0;
}
