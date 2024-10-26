#include <iostream>

using namespace std;

int main() {

    // Declaración de variables.

    string nombre, producto_precio_mayor, producto_precio_menor, producto_cantidad_mayor, producto_cantidad_menor;
    int cantidad, codigo, editar, limite, opt, opt_listado, opt_editar, config;
    int cantidad_mayor = 0, cantidad_menor = 0;
    int volver = 0, volver2 = 0, volver3 = 0, terminar = 1, e = 0;
    int bs = 39;
    double precio_mayor = 0, precio_menor = 0, preciobsneto = 0;
    double preciobsbruto, bruto, neto1, neto2;
    double iva1 = 16, iva2 = 0, suma = 0;
    string vector_nombre[50];
    int vector_productos[50], vector_codigo[50], vector_cantidad[50];
    double vector_precio[50];
    bool vector_exento[50];

    do {

        // Menú principal.

        cout << "         MENU." << endl;
        cout << "\n1. AGREGAR PRODUCTOS." << endl;
        cout << "2. MODIFICAR PRODUCTOS." << endl;
        cout << "3. LISTADO DE PRODUCTOS." << endl;
        cout << "4. ESTADISTICAS." << endl;
        cout << "5. CONFIGURACION." << endl;
        cout << "6. SALIR." << endl;
        cout << "\nINGRESE UNA OPCION: " << endl;
        cin >> opt;

        system("clear");

        switch(opt) {

            case 1: // Registro de productos.
            cout << "\nINGRESE LA CANTIDAD DE PRODUCTOS A REGISTRAR: ";
            cin >> limite;

            suma += limite;

            for(int i = 0; i < limite; i++) {

                cout << "\n- Ingrese el nombre del producto " << i+1 << ": ";
                cin >> vector_nombre[i];

                cout << "- ¿Cuantos " << vector_nombre[i] << " quiere?: ";
                cin >> vector_cantidad[i];

                cout << "- Ingrese el precio del producto: ";
                cin >> vector_precio[i];

                cout << "- Ingrese el codigo del producto: ";
                cin >> vector_codigo[i];

                cout << "- ¿El producto esta exento de IVA? (Si = 1, No = 0): ";
                cin >> vector_exento[i];

                bruto += vector_precio[i];

                if(i == 0) {
                    precio_mayor = vector_precio[i];
                    precio_menor = vector_precio[i];
                }
                else {
                    if(vector_precio[i] > precio_mayor) {
                        precio_mayor = vector_precio[i];
                        producto_precio_mayor = vector_nombre[i];
                    }
                    if(vector_precio[i] < precio_menor) {
                        precio_menor = vector_precio[i];
                        producto_precio_menor = vector_nombre[i];
                    }
                }

                if(i == 0) {
                    cantidad_mayor = vector_cantidad[i];
                    cantidad_menor = vector_cantidad[i];
                }
                else {
                    if(vector_cantidad[i] > cantidad_mayor) {
                        cantidad_mayor = vector_cantidad[i];
                        producto_cantidad_mayor = vector_nombre[i];
                    }
                    if(vector_cantidad[i] < cantidad_menor) {
                        cantidad_menor = vector_cantidad[i];
                        producto_cantidad_menor = vector_nombre[i];
                    }
                }

            }

            system("clear");
            break;

            case 2: // Edición de productos.
            cout << "\n¿QUE PRODUCTO DESEA EDITAR?" << endl;

            for(int e = 0; e < limite; e++) {
                cout << e << "." << vector_nombre[e] << endl;
            }

            int u;
            cin >> u;

            cout << "\n¿QUE APARTADO DESEA EDITAR?" << endl;
            cout << "\n1. Nombre." << endl;
            cout << "2. Precio." << endl;
            cout << "3. Codigo." << endl;
            cout << "4. Cantidad." << endl;

            cin >> opt_editar;

            do {

                switch(opt_editar) {

                    case 1: cout << vector_nombre[u] << " pasara a llamarse: ";
                    cin >> vector_nombre[u];

                    cout << "(Para volver presione 1): ";
                    cin >> volver3;
                    system("clear");
                    break;

                    case 2: cout << vector_nombre[u] << " pasara a costar: ";
                    cin >> vector_precio[u];

                    cout << "(Para volver presione 1): ";
                    cin >> volver3;
                    system("clear");
                    break;

                    case 3: cout << vector_nombre[u] << " pasara a tener el codigo: ";
                    cin >> vector_codigo[u];

                    cout << "(Para volver presione 1): ";
                    cin >> volver3;
                    system("clear");
                    break;

                    case 4: cout << vector_nombre[u] << " pasara a tener la cantidad de: ";
                    cin >> vector_cantidad[u];

                    cout << "(Para volver presione 1): ";
                    cin >> volver3;
                    system("clear");
                    break;
                }

            } while(volver3 = 0);

            system("clear");
            break;

            case 3: // Listado.
            cout << "\nLISTADO DE PRODUCTOS." << endl;

            for(int e = 0; e < limite; e++) {
                cout << e << "." << vector_nombre[e] << endl;
            }

            cout << "\n¿A QUE PRODUCTO DESEA INGRESAR?" << endl;
            cin >> opt_listado;

            do {

                switch(opt_listado) {

                    case 0: cout << "\nEstadisticas del producto " << vector_nombre[0] << endl;
                    cout << "- Precio: " << vector_precio[0] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[0] << endl;
                    cout << "- Cantidad: " << vector_cantidad[0] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[0] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                    case 1: cout << "\nEstadisticas del producto " << vector_nombre[1] << endl;
                    cout << "- Precio: " << vector_precio[1] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[1] << endl;
                    cout << "- Cantidad: " << vector_cantidad[1] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[1] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                    case 2: cout << "\nEstadisticas del producto " << vector_nombre[2] << endl;
                    cout << "- Precio: " << vector_precio[2] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[2] << endl;
                    cout << "- Cantidad: " << vector_cantidad[2] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[2] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                    case 3: cout << "\nEstadisticas del producto " << vector_nombre[3] << endl;
                    cout << "- Precio: " << vector_precio[3] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[3] << endl;
                    cout << "- Cantidad: " << vector_cantidad[3] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[3] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                    case 4: cout << "\nEstadisticas del producto " << vector_nombre[4] << endl;
                    cout << "- Precio: " << vector_precio[4] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[4] << endl;
                    cout << "- Cantidad: " << vector_cantidad[4] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[4] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                    case 5: cout << "\nEstadisticas del producto " << vector_nombre[5] << endl;
                    cout << "- Precio: " << vector_precio[5] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[5] << endl;
                    cout << "- Cantidad: " << vector_cantidad[5] << endl;
                    cout << "- Exento de IVA: " << (vector_exento[5] ? "Si" : "No") << endl;

                    cout << "---------------------------------" << endl;
                    cout << "\n(Para volver presione 1): ";
                    cin >> volver;

                    system("clear");
                    break;

                }

            } while(volver = 0);
            break;

            case 4: // Estadísticas.
            cout << "\nLAS ESTADISTICAS SON:" << endl;

            do {

                system("clear");

                iva2 = iva1 / 100;
                neto1 = bruto * iva2;
                neto2 = bruto - neto1;
                preciobsneto = neto2 * bs;
                preciobsbruto = bruto * bs;

                cout << "\n              ESTADISTICAS DE LA ULTIMA LISTA:" << endl;
                cout << "- El producto mas costoso es " << producto_precio_mayor << " con un precio de " << precio_mayor << " dolares ($)." << endl;
                cout << "- El producto menos costoso es " << producto_precio_menor << " con un precio de " << precio_menor << " dolares ($)." << endl;
                cout << "- El producto con mayor cantidad es " << producto_cantidad_mayor << " con un total de " << cantidad_mayor << " unidades." << endl;
                cout << "- El producto con menor cantidad es " << producto_cantidad_menor << " con un total de " << cantidad_menor << " unidades." << endl;

                cout << "\n              ESTADISTICAS TOTALES:" << endl;
                cout << "- La cantidad total de productos es de " << suma << " productos." << endl;
                cout << "- EL total neto es " << neto2 << " dolares ($), y " << preciobsneto << " BS." << endl;
                cout << "- El total bruto es " << bruto << " dolares ($), y " << preciobsbruto << " BS." << endl;

                cout << "---------------------------------" << endl;

                cout << "\n(Para volver presione 1): ";
                cin >> volver2;

            } while (volver2 == 0);
            system("clear");
            break;

            case 5: // Configuración.
            cout << "\nTASA DE CAMBIOS: BS E IVA.";
            cout << "\n- El precio actual del dolar ($) es de " << bs << " BS, y el IVA es del " << iva1 << "%." << endl;

            cout << "\n¿QUE DESEA CONFIGURAR? \nBS = 1,     IVA = 2,     SALIR = 0." << endl;
            cin >> config;

            if(config == 1) {
                cout << "- ¿Cual es el nuevo precio del dolar?" << endl;
                cin >> bs;
            }
            else if(config == 2) {
                cout << "- ¿Cual es el nuevo porcentaje del IVA?" << endl;
                cin >> iva1;
            }

            system("clear");
            break;

            case 6: // Salir.
            cout << "\n¿DESEA CONTINUAR CON EL PROGRAMA? \nSi = 1,     No = 0." << endl;
            cin >> terminar;

            system("pause");
            system("clear");

        }


    } while (terminar == 1);

}