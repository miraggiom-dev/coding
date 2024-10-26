#include <iostream>

using namespace std;

int main() {

    // Declaración de variables.
    string producto_precio_mayor, producto_precio_menor;
    string producto_cantidad_mayor, producto_cantidad_menor;
    string vector_nombre[50], vector_exento[50];
    int vector_productos[50], vector_codigo[50], vector_cantidad[50];
    int codigo, limite, opcion, opt_listado, opt_editar, config;
    int cantidad_mayor = 0, cantidad_menor = 999, productos_con_cantidad_cero = 0;
    int terminar = 1, volver = 0, volver2 = 0, volver3 = 0, e = 0;
    double precio_mayor = 0, precio_menor = 999, preciobsneto = 0, preciobsbruto = 0;
    double bs = 39, iva1 = 16, iva2 = 0, bruto1 = 0, bruto2 = 0, productos = 0;
    double neto1, neto2;
    double vector_precio[50];
    
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
        cin >> opcion;

        // Validación de entrada de opción.
        while (opcion < 1 || opcion > 6) {
            cout << "\nOpción inválida, por favor ingrese una opción entre 1 y 6: ";
            cin >> opcion;
        }

        system("clear");

        switch(opcion) {

            case 1: // Registro de productos.
            cout << "\nINGRESE LA CANTIDAD DE PRODUCTOS A REGISTRAR: ";
            cin >> limite;

            // Validación de entrada de límite.
            while (limite <= 0) {
                cout << "Cantidad inválida, por favor ingrese una cantidad mayor o igual que cero: ";
                cin >> limite;
            }

            productos += limite;

            // Ingreso de datos de los productos.
            for(int i = 0; i < limite; i++) {

                // Nombre del producto.
                cout << "\n- Ingrese el nombre del producto " << i+1 << ": ";
                cin >> vector_nombre[i];

                // Cantidad del producto.
                cout << "- ¿Cuantos " << vector_nombre[i] << " quiere?: ";
                cin >> vector_cantidad[i];

                // Validación de cantidad.
                while (vector_cantidad[i] < 0) {
                    cout << "La cantidad es invalida. Por favor, ingrese otra: ";
                    cin >> vector_cantidad[i];
                }

                // Crear estadísticas de cantidad.
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

                // Validación de precio.
                while (vector_precio[i] < 0) {
                    cout << "El precio es invalido. Por favor, ingrese otro: ";
                    cin >> vector_precio[i];
                }

                // Crear estadísticas de precios.
                if (vector_precio[i] > precio_mayor) {
                    precio_mayor = vector_precio[i];
                    producto_precio_mayor = vector_nombre[i];
                }
                if (vector_precio[i] < precio_menor) {
                    precio_menor = vector_precio[i];
                    producto_precio_menor = vector_nombre[i];
                }

                // Ingreso de código.
                bool codigo_repetido;
                do {
                    cout << "- Ingrese el codigo del producto: ";
                    cin >> codigo;

                    // Verificar si el código ya está en uso.
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
                cout << "- ¿El producto " << vector_nombre[i] << " está exento de IVA? (Y/N): ";
                cin >> vector_exento[i];

                // Validación de exención de IVA.
                while (vector_exento[i] != "Y" && vector_exento[i] != "N") {
                    cout << "Entrada inválida. Por favor ingrese 'Y' para sí o 'N' para no: ";
                    cin >> vector_exento[i];
                }
                break;

                // Calcular el precio bruto solo si no está exento de IVA.
                if (vector_exento[i] == "N") {
                    bruto1 = (bruto1 + vector_precio[i])*vector_cantidad[i];
                } else {
                    // Si está exento, solo se suma el precio a los productos, pero no al bruto.
                    bruto2 = (bruto2 + vector_precio[i])*vector_cantidad[i];
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

                    // Validación de precio.
                    while (vector_precio[u] < 0) {
                        cout << "El precio es invalido. Por favor, ingrese otro: ";
                        cin >> vector_precio[u];
                    }

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


                }
                cout << "\n---------------------------------" << endl;
                cout << "(Para volver presione 1): ";
                cin >> volver3;

            } while(volver3 == 0);

            // Actualizar estadísticas del precio bruto.
            bruto1 = 0;
            bruto2 = 0;
            if (vector_exento[u] == "N") {
                bruto1 = (bruto1 + vector_precio[u])*vector_cantidad[u];
            } else {
            // Si está exento, solo se suma el precio a los productos, pero no al bruto.
                bruto2 = (bruto2 + vector_precio[u])*vector_cantidad[u];
            }

            // Actualizar estadísticas de cantidad.
            productos = 0;
            for(int i = 0; i < limite; i++) {
                productos += vector_cantidad[i];
            }

            if (vector_cantidad[u] > cantidad_mayor) {
                cantidad_mayor = vector_cantidad[u];
                producto_cantidad_mayor = vector_nombre[u];
            }
            if (vector_cantidad[u] < cantidad_menor) {
                cantidad_menor = vector_cantidad[u];
                producto_cantidad_menor = vector_nombre[u];
            }

            // Actualizar estadísticas de precios.
            productos += vector_precio[u];

            if (vector_precio[u] > precio_mayor) {
                precio_mayor = vector_precio[u];
                producto_precio_mayor = vector_nombre[u];
            }
            if (vector_precio[u] < precio_menor) {
                precio_menor = vector_precio[u];
                producto_precio_menor = vector_nombre[u];
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
                    cout << "\n- Nombre: " << vector_nombre[i] << endl;
                    cout << "- Cantidad: " << vector_cantidad[i] << endl;
                    cout << "- Precio: " << vector_precio[i] << " dolares ($)." << endl;
                    cout << "- Codigo: " << vector_codigo[i] << endl;
                    cout << "- Exento de IVA: " << vector_exento[i] << endl;

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

            for(int i = 0; i < limite; i++) {
                if(vector_cantidad[i] == 0) {
                    productos_con_cantidad_cero++;
                }
            }

            iva2 = iva1 / 100;
            neto1 = bruto1 * iva2;
            neto2 = bruto2 + neto1;
            preciobsneto = neto2 * bs;
            preciobsbruto = bruto1 * bs;

            cout << "\n                ESTADISTICAS DE LA ULTIMA LISTA:" << endl;
            cout << "- El producto mas costoso es " << producto_precio_mayor << " con un precio de " << precio_mayor << " dolares ($)." << endl;
            cout << "- El producto menos costoso es " << producto_precio_menor << " con un precio de " << precio_menor << " dolares ($)." << endl;
            cout << "- El producto con mayor cantidad es " << producto_cantidad_mayor << " con un total de " << cantidad_mayor << " unidades." << endl;
            cout << "- El producto con menor cantidad es " << producto_cantidad_menor << " con un total de " << cantidad_menor << " unidades." << endl;

            cout << "\n              ESTADISTICAS TOTALES:" << endl;
            cout << "- La cantidad total es de " << productos << " productos." << endl;
            cout << "- El total neto es " << neto2 << " dolares ($), y " << preciobsneto << " BS." << endl;
            cout << "- El total bruto es " << bruto1 << " dolares ($), y " << preciobsbruto << " BS." << endl;
            cout << "- Total de productos con cantidad cero: " << productos_con_cantidad_cero << endl;

            cout << "\n---------------------------------" << endl;
            cout << "(Para volver presione 1): ";
            cin >> volver2;
        
            system("clear");

            if(volver2 == 1) {
                break;
            }

            case 5: // Configuración.
            cout << "\n                 TASA DE CAMBIOS: BS E IVA.";
            cout << "\nEl precio actual del dolar ($) es de " << bs << " BS, y el IVA es del " << iva1 << "%." << endl;

            cout << "\n¿QUE DESEA CONFIGURAR? \nBS = 1,     IVA = 2,     SALIR = 0." << endl;
            cin >> config;

            if(config == 1) {
                cout << "\n- ¿Cual es el nuevo precio del dolar?" << endl;
                cin >> bs;
            }
            else if(config == 2) {
                cout << "\n- ¿Cual es el nuevo porcentaje del IVA?" << endl;
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

    } while(terminar == 1);

}