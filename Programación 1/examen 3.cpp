#include <iostream>

using namespace std;

int main() {

    // Declaracion de variables.
    string producto_precio_mayor, producto_precio_menor;
    string producto_cantidad_mayor, producto_cantidad_menor, productos_con_exentos;
    string vector_nombre[50], vector_exento[50];
    int vector_productos[50], vector_codigo[50], vector_cantidad[50];
    int limite = 100, codigo, opcion, opt_listado, opt_editar, config;
    int productos = 0, cantidad_mayor = 0, cantidad_menor = 999, productos_con_cantidad_cero = 0;
    int terminar = 1, volver = 0, volver2 = 0, volver3 = 0, e = 0;
    double precio_bruto = 0, precio_neto = 0, precio_bruto_bs = 0, precio_neto_bs = 0;
    double precio_mayor = 0, precio_menor = 999;
    double vector_precio[50], bs = 39, iva = 16, iva_porcentaje = 0;
    
    do {

        // Menu principal.
        cout << "         MENU." << endl;
        cout << "\n1. AGREGAR PRODUCTOS." << endl;
        cout << "2. MODIFICAR PRODUCTOS." << endl;
        cout << "3. LISTADO DE PRODUCTOS." << endl;
        cout << "4. ESTADISTICAS." << endl;
        cout << "5. CONFIGURACION." << endl;
        cout << "6. SALIR." << endl;
        cout << "\nINGRESE UNA OPCION: ";
        cin >> opcion;

        system("cls");

        switch(opcion) {

            case 1: // Registro de productos.
                cout << "\nINGRESE LA CANTIDAD DE PRODUCTOS A REGISTRAR: ";
                cin >> limite;

                // Validacion de entrada de limite.
                while (limite <= 0) {
                    cout << "Cantidad invalida, por favor ingrese una cantidad mayor o igual que cero: ";
                    cin >> limite;
                }

                productos += limite;

                // Ingreso de datos de los productos.
                for(int i = 0; i < limite; i++) {

                    // Nombre del producto.
                    cout << "\n- Ingrese el nombre del producto " << i+1 << ": ";
                    cin >> vector_nombre[i];

                    // Cantidad del producto.
                    cout << "- Ingrese la cantidad deseada: ";
                    cin >> vector_cantidad[i];

                    // Validacion de cantidad.
                    while (vector_cantidad[i] < 0) {
                        cout << "La cantidad es invalida. Por favor, ingrese otra: ";
                        cin >> vector_cantidad[i];
                    }

                    // Crear estadisticas de cantidad.
                    if (vector_cantidad[i] > cantidad_mayor) {
                        cantidad_mayor = vector_cantidad[i];
                        producto_cantidad_mayor = vector_nombre[i];
                    }
                    if (vector_cantidad[i] < cantidad_menor) {
                        cantidad_menor = vector_cantidad[i];
                        producto_cantidad_menor = vector_nombre[i];
                    }

                    // Precio del producto.
                    cout << "- Ingrese el precio del producto: ";
                    cin >> vector_precio[i];

                    // Validacion de precio.
                    while (vector_precio[i] < 0) {
                        cout << "El precio es invalido. Por favor, ingrese otro: ";
                        cin >> vector_precio[i];
                    }

                    // Crear estadisticas de precios.
                    if (vector_precio[i] > precio_mayor) {
                        precio_mayor = vector_precio[i];
                        producto_precio_mayor = vector_nombre[i];
                    }
                    if (vector_precio[i] < precio_menor) {
                        precio_menor = vector_precio[i];
                        producto_precio_menor = vector_nombre[i];
                    }

                    // Ingreso de codigo.
                    bool codigo_repetido;
                    do {
                        cout << "- Ingrese el codigo del producto: ";
                        cin >> codigo;

                        // Verificar si el codigo ya esta en uso.
                        codigo_repetido = false;
                        for(int j = 0; j < i; j++) {
                            if(vector_codigo[j] == codigo) {
                                cout << "El codigo ya esta en uso, por favor ingrese otro." << endl;
                                codigo_repetido = true;
                                break;
                            }
                        }
                    } while(codigo_repetido);
                    vector_codigo[i] = codigo;

                    // Preguntar si el producto está exento de IVA.
                    cout << "- ¿El producto está exento de IVA? (Y/N): ";
                    cin >> vector_exento[i];

                    // Cálculo del precio bruto
                    precio_bruto += vector_precio[i] * vector_cantidad[i];

                    // Cálculo del precio neto.
                    iva_porcentaje = iva/100;
                    if (vector_exento[i] == "N") {
                        double precio_con_iva = vector_precio[i] * (1 + iva_porcentaje); // Precio con IVA.
                        precio_neto += precio_con_iva * vector_cantidad[i];
                    } else {
                        precio_neto += vector_precio[i] * vector_cantidad[i]; // Solo precio bruto.
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

                system("clear");

                cout << "\n¿QUE APARTADO DESEA EDITAR?" << endl;
                cout << "\n1. Nombre." << endl;
                cout << "2. Precio." << endl;
                cout << "3. Codigo." << endl;
                cout << "4. Cantidad." << endl;
                cout << "5. Exento de IVA." << endl;
                cout << "\nINGRESE UNA OPCION: ";
                cin >> opt_editar;

                // Validación de entrada de opción a editar.
                while (opt_editar < 1 || opt_editar > 5) {
                    cout << "\nOpción inválida, por favor ingrese una opción entre 1 y 5: ";
                    cin >> opt_editar;
                }

                do { // Edición de los datos.

                    switch(opt_editar) {

                        case 1: // Nombre.
                        cout << vector_nombre[u] << " pasará a llamarse: ";
                        cin >> vector_nombre[u];
                        break;

                        case 2: // Precio.
                        cout << vector_nombre[u] << " pasará a costar: ";
                        cin >> vector_precio[u];
                        break;

                        // Validación de precio.
                        while (vector_precio[u] < 0) {
                            cout << "El precio es invalido. Por favor, ingrese otro: ";
                            cin >> vector_precio[u];
                        }
                        break;

                        case 3: // Código.
                        cout << vector_nombre[u] << " pasará a tener el código: ";
                        cin >> vector_codigo[u];
                        break;

                    case 4: // Cantidad.
                    cout << vector_nombre[u] << " pasará a tener la cantidad de: ";
                    cin >> vector_cantidad[u];

                    // Validación de cantidad.
                    while (vector_cantidad[u] < 0) {
                        cout << "La cantidad es invalida. Por favor, ingrese otra: ";
                        cin >> vector_cantidad[u];
                    }
                    break;

                    case 5: // Exento de IVA.
                    cout << "- ¿El producto está exento de IVA? (Y/N): ";
                    cin >> vector_exento[u];
                    break;

                    default:
                    cout << "Error, no existe esa opcion.";
                    break;
                }
                cout << "\n---------------------------------" << endl;
                cout << "(Para volver presione 1): ";
                cin >> volver3;

            } while(volver3 == 0);

                // Actualizar cálculo del precio bruto.
                precio_bruto = 0; // Reiniciar para recalcular
                precio_neto = 0; // Reiniciar para recalcular
                for (int i = 0; i < limite; i++) {
                    precio_bruto += vector_precio[i] * vector_cantidad[i];
                    iva_porcentaje = iva / 100;
                    if (vector_exento[i] == "N") {
                        double precio_con_iva = vector_precio[i] * (1 + iva_porcentaje); // Precio con IVA.
                        precio_neto += precio_con_iva * vector_cantidad[i];
                    } else {
                        precio_neto += vector_precio[i] * vector_cantidad[i]; // Solo precio bruto.
                    }
                }

                // Actualizar estadísticas de cantidad.
                for(int i = 0; i < limite; i++) {
                    if(vector_cantidad[i] == 0) {
                        productos_con_cantidad_cero++;
                    }
                }

                cantidad_mayor = 0;
                cantidad_menor = 999;
                producto_cantidad_mayor = "";
                producto_cantidad_menor = "";

                for (int i = 0; i < limite; i++) {
                    if (vector_cantidad[i] > cantidad_mayor) {
                        cantidad_mayor = vector_cantidad[i];
                        producto_cantidad_mayor = vector_nombre[i];
                    }
                    if (vector_cantidad[i] < cantidad_menor) {
                        cantidad_menor = vector_cantidad[i];
                        producto_cantidad_menor = vector_nombre[i];
                    }
                }

                // Actualizar estadísticas de precios.
                precio_mayor = 0;
                precio_menor = 999;
                producto_precio_mayor = "";
                producto_precio_menor = "";

                for (int i = 0; i < limite; i++) {
                    if (vector_precio[i] > precio_mayor) {
                        precio_mayor = vector_precio[i];
                        producto_precio_mayor = vector_nombre[i];
                    }
                    if (vector_precio[i] < precio_menor) {
                        precio_menor = vector_precio[i];
                        producto_precio_menor = vector_nombre[i];
                    }
                }

                system("clear");
                break;

            case 3: // Mostrar listado.
                cout << "\nLISTADO DE PRODUCTOS." << endl;

                for(int e = 0; e < limite; e++) {
                    cout << e << "." << vector_nombre[e] << endl;
                }

                cout << "\n¿A QUE PRODUCTO DESEA INGRESAR?" << endl;
                cin >> opt_listado;

                for(int i = 0; i < limite; i++) {
                    if(opt_listado == i) {
                        cout << "\n- Nombre: " << vector_nombre[opt_listado] << endl;
                        cout << "- Cantidad: " << vector_cantidad[opt_listado] << endl;
                        cout << "- Precio: " << vector_precio[opt_listado] << " dolares ($)." << endl;
                        cout << "- Codigo: " << vector_codigo[opt_listado] << endl;
                        cout << "- Exento de IVA: " << vector_exento[opt_listado] << endl;

                        cout << "\n---------------------------------" << endl;
                        cout << "(Para volver presione 1): ";
                        cin >> volver;

                        system("clear");
                    }
                }

                if(volver == 1) {
                    break;
                }

            case 4: // Estadísticas.
                cout << "\nLAS ESTADISTICAS SON:" << endl;

                precio_bruto_bs = precio_bruto * bs;
                precio_neto_bs = precio_neto * bs;

                // Recalcular la cantidad de productos con cantidad cero.
                productos_con_cantidad_cero = 0; // Reiniciar el contador
                for(int i = 0; i < limite; i++) {
                    if(vector_cantidad[i] == 0) {
                        productos_con_cantidad_cero++;
                    }
                }

                // Mostrar estadísticas de los productos totales.
                cout << "\n                     ESTADISTICAS TOTALES:" << endl;
                cout << "- El producto mas costoso es " << producto_precio_mayor << " con un precio de " << precio_mayor << " dolares ($)." << endl;
                cout << "- El producto menos costoso es " << producto_precio_menor << " con un precio de " << precio_menor << " dolares ($)." << endl;
                cout << "- El producto con mayor cantidad es " << producto_cantidad_mayor << " con un total de " << cantidad_mayor << " unidades." << endl;
                cout << "- El producto con menor cantidad es " << producto_cantidad_menor << " con un total de " << cantidad_menor << " unidades." << endl;
                cout << "- La cantidad total es de " << productos << " productos." << endl;
                cout << "- Precio bruto total: " << precio_bruto << " dolares ($) y " << precio_bruto_bs << " bolivares (Bs)." << endl;
                cout << "- Precio neto total: " << precio_neto << " dolares ($) y " << precio_neto_bs << " bolivares (Bs)." << endl;
                cout << "- Total de productos con cantidad cero: " << productos_con_cantidad_cero << endl;

                // Mostrar listado de productos exentos de IVA
                cout << "\n              PRODUCTOS EXENTOS DE IVA:" << endl;
                for (int i = 0; i < vector_cantidad[i]; i++) {
                    if (vector_exento[i] == "Y") { // Si el producto está exento de IVA
                        cout << "- " << vector_nombre[i] << endl;
                        productos_con_exentos += vector_nombre[i];
                    }
                }

                cout << "\n---------------------------------" << endl;
                cout << "(Para volver presione 1): ";
                cin >> volver2;
            
                system("clear");

                if(volver2 == 1) {
                    break;
                }

            case 5: // Configuración.
                cout << "\n                 TASA DE CAMBIOS: BS E IVA.";
                cout << "\nEl precio actual del dolar ($) es de " << bs << " BS, y el IVA es del " << iva << "%." << endl;

                cout << "\n¿QUE DESEA CONFIGURAR? \nBS = 1,     IVA = 2,     SALIR = 0." << endl;
                cin >> config;

                if(config == 1) {
                    cout << "\n- ¿Cual es el nuevo precio del dolar?" << endl;
                    cin >> bs;
                }
                else if(config == 2) {
                    cout << "\n- ¿Cual es el nuevo porcentaje del IVA?" << endl;
                    cin >> iva;
                }

                // Recalcular el precio neto después de cambiar el IVA.
                precio_bruto = 0; // Reiniciar para recalcular.
                precio_neto = 0; // Reiniciar para recalcular.
                for (int i = 0; i < limite; i++) {
                    precio_bruto += vector_precio[i] * vector_cantidad[i];
                    iva_porcentaje = iva / 100;
                    if (vector_exento[i] == "N") {
                        double precio_con_iva = vector_precio[i] * (1 + iva_porcentaje); // Precio con IVA.
                        precio_neto += precio_con_iva * vector_cantidad[i];
                    } else {
                        precio_neto += vector_precio[i] * vector_cantidad[i]; // Solo precio bruto.
                    }
                }

                system("clear");
                break;

            case 6: // Salir.
                cout << "\n¿DESEA CONTINUAR CON EL PROGRAMA? \nSi = 1,     No = 0." << endl;
                cin >> terminar;

                system("pause");
                system("clear");

            default:
                cout << "Error, no existe esa opcion.";
            break;

        }

    } while (terminar == 1);

}
