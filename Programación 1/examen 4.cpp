#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    // Declaración de variables.

    // Variables para estadisticas.
    string estudiante_mayor_edad, estudiante_menor_edad;
    string estudiante_promedio_alto, estudiante_promedio_bajo;
    string estudiante_mayor_cantidad_notas, estudiante_menor_cantidad_notas;
    int mayor_cantidad_notas = 0, menor_cantidad_notas = 999;
    int mayor_edad = 0, menor_edad = 999;
    int cantidad_hombres = 0, cantidad_mujeres = 0;
    double promedio_alto = 0, promedio_bajo = 999;

    // Variables para registro de estudiantes.
    string vector_nombre[20], vector_apellido[20], vector_genero[20], vector_cedula[20];
    int vector_fecha_nacimiento[20][3], fecha_actual[3];
    int estudiantes = 20, cantidad_estudiantes = 0;
    int vector_cantidad_notas[20];
    double nota[20][20];

    // Variables para cálculo de promedio.
    double promedios[20], suma_notas = 0, suma_nueva_notas = 0;

    // Variables para opciones y terminar.
    string cedula_buscada;
    bool encontrado = false;
    int opcion, opt_listado, opt_editar, opt_matriz;
    int terminar = 1, volver = 0, volver2 = 0, volver3 = 0;

    // Variables para matrices.
    string salon_hombres[20][2], salon_mujeres[20][2], salon_todos[20][2], salon_aprobados[20][2], salon_reprobados[20][2];

    fecha_actual[0] = 25;
    fecha_actual[1] = 10;
    fecha_actual[2] = 2024;

    do
    {

        // Menú principal.
        cout << "    SISTEMA DE ESTUDIANTES." << endl;
        cout << "\n1. AGREGAR ESTUDIANTES." << endl;
        cout << "2. MODIFICAR ESTUDIANTES." << endl;
        cout << "3. LISTADO DE ESTUDIANTES." << endl;
        cout << "4. ESTADISTICAS." << endl;
        cout << "5. MATRIZ DE RESULTADOS." << endl;
        cout << "6. SALIR." << endl;
        cout << "\nINGRESE UNA OPCION: ";
        cin >> opcion;

        system("clear");

        switch (opcion)
        {

        case 1:
        { // Agregar estudiantes.
            cout << "\nINGRESE LA CANTIDAD DE ESTUDIANTES A REGISTRAR: ";
            cin >> estudiantes;

            // Ingreso de datos de los estudiantes.
            for (int i = 0; i < estudiantes; i++)
            {

                // Nombre.
                cout << "\n- Ingrese el nombre del estudiante " << i + 1 << ": ";
                cin >> vector_nombre[i];

                // Apellido.
                cout << "- Ingrese el apellido del estudiante " << i + 1 << ": ";
                cin >> vector_apellido[i];

                // Fecha de nacimiento.
                cout << "- Ingrese la fecha de nacimiento del estudiante " << i + 1 << " (DD/MM/AAAA): ";
                cin >> vector_fecha_nacimiento[i][0] >> vector_fecha_nacimiento[i][1] >> vector_fecha_nacimiento[i][2];

                // Genero.
                cout << "- Ingrese el genero del estudiante " << i + 1 << " (H/M): ";
                cin >> vector_genero[i];

                // Cedula.
                cout << "- Ingrese la cedula del estudiante " << i + 1 << ": ";
                cin >> vector_cedula[i];

                // Notas.
                cout << "- Ingrese la cantidad de notas del estudiante " << i + 1 << ": ";
                cin >> vector_cantidad_notas[i];

                suma_notas = 0;

                for (int j = 0; j < vector_cantidad_notas[i]; j++)
                {
                    while (true)
                    {
                        cout << "- Introduzca la nota del estudiante " << vector_nombre[i] << ": ";
                        cin >> nota[i][j];

                        if (nota[i][j] < 0 || nota[i][j] > 20)
                        {
                            cout << "Nota invalida. Por favor, introduzca una nota entre 0 y 20." << endl;
                        }
                        else
                        {
                            suma_notas += nota[i][j];
                            break;
                        }
                    }
                }

                // Verificacion de edad para cada persona.
                for (int i = 0; i < estudiantes; i++)
                {
                    int edad = fecha_actual[2] - vector_fecha_nacimiento[i][2]; // Calcular la diferencia de años.

                    // Ajustar la edad si el cumpleaños no ha ocurrido aun en el año actual.
                    if (vector_fecha_nacimiento[i][1] > fecha_actual[1] || (vector_fecha_nacimiento[i][1] == fecha_actual[1] && vector_fecha_nacimiento[i][0] > fecha_actual[0]))
                    {
                        edad--; // Si el cumpleaños no ha ocurrido, restar un año
                    }

                    // Verificar si la persona es mayor de edad.
                    if (edad >= 18)
                    {
                        mayor_edad = edad;
                        estudiante_mayor_edad = vector_nombre[i];
                    }
                    if (edad < 18)
                    {
                        menor_edad = edad;
                        estudiante_menor_edad = vector_nombre[i];
                    }
                }

                // Calculo para promedio alto y bajo.
                promedios[i] = suma_notas / vector_cantidad_notas[i];

                if (promedios[i] > promedio_alto)
                {
                    promedio_alto = promedios[i];
                    estudiante_promedio_alto = vector_nombre[i];
                }

                if (promedios[i] < promedio_bajo)
                {
                    promedio_bajo = promedios[i];
                    estudiante_promedio_bajo = vector_nombre[i];
                }

                if (vector_cantidad_notas[i] > mayor_cantidad_notas)
                {
                    mayor_cantidad_notas = vector_cantidad_notas[i];
                    estudiante_mayor_cantidad_notas = vector_nombre[i];
                }

                if (vector_cantidad_notas[i] < menor_cantidad_notas)
                {
                    menor_cantidad_notas = vector_cantidad_notas[i];
                    estudiante_menor_cantidad_notas = vector_nombre[i];
                }
            }

            system("clear");
            break;
        }

        case 2:
        { // Modificar estudiantes.
            cout << "\nSELECCIONE EL ESTUDIANTE A EDITAR: " << endl;

            for (int i = 0; i < estudiantes; i++)
            {
                cout << i << ". " << vector_nombre[i] << vector_apellido[i] << endl;
            }

            int u;
            cin >> u;
            u--;

            system("clear");

            cout << "\nSELECCIONE EL APARTADO A EDITAR." << endl;
            cout << "\n1. Nombre." << endl;
            cout << "2. Apellido." << endl;
            cout << "3. Fecha de nacimiento." << endl;
            cout << "4. Genero." << endl;
            cout << "5. Cedula." << endl;
            cout << "6. Notas." << endl;
            cout << "\nINGRESE UNA OPCION: ";
            cin >> opt_editar;

            do
            { // Edicion de los datos.

                switch (opt_editar)
                {

                case 1: // Nombre.
                    cout << "\n- Ingrese el nuevo nombre del estudiante: ";
                    cin >> vector_nombre[u];
                    break;

                case 2: // Apellido.
                    cout << "\n- Ingrese el nuevo apellido del estudiante: ";
                    cin >> vector_apellido[u];
                    break;

                case 3: // Fecha de nacimiento.
                    cout << "\n- Ingrese la nueva fecha de nacimiento del estudiante (DD/MM/AAAA): ";
                    cin >> vector_fecha_nacimiento[u][0] >> vector_fecha_nacimiento[u][1] >> vector_fecha_nacimiento[u][2];
                    break;

                case 4: // Genero.
                    cout << "\n- Ingrese el nuevo genero del estudiante (H/M): ";
                    cin >> vector_genero[u];
                    break;

                case 5: // Cedula.
                    cout << "\n- Ingrese la nueva cedula del estudiante: ";
                    cin >> vector_cedula[u];
                    break;

                case 6: // Notas.
                    cout << "\n- Ingrese la nueva cantidad de notas del estudiante: ";
                    cin >> vector_cantidad_notas[u];
                    suma_notas = 0; // Reiniciar suma de notas

                    for (int j = 0; j < vector_cantidad_notas[u]; j++)
                    {
                        while (true)
                        {
                            cout << "- Introduzca la nueva nota del estudiante " << vector_nombre[u] << ": ";
                            cin >> nota[u][j];

                            if (nota[u][j] < 0 || nota[u][j] > 20)
                            {
                                cout << "Nota invalida. Por favor, introduzca una nota entre 0 y 20." << endl;
                            }
                            else
                            {
                                suma_notas += nota[u][j];
                                break;
                            }
                        }
                    }
                    break;
                }
                cout << "\n---------------------------------" << endl;
                cout << "(Para volver presione 1): ";
                cin >> volver3;

            } while (volver3 == 1);

            // Reinicializar variables para actualizar estadísticas.
            mayor_edad = 0;
            menor_edad = 999;
            mayor_cantidad_notas = 0;
            menor_cantidad_notas = 999;
            promedio_alto = 0;
            promedio_bajo = 999;

            // Recalcular estadísticas
            for (int i = 0; i < estudiantes; i++)
            {

                // Calcular edad
                int edad = fecha_actual[2] - vector_fecha_nacimiento[i][2];
                if (vector_fecha_nacimiento[i][1] > fecha_actual[1] ||
                    (vector_fecha_nacimiento[i][1] == fecha_actual[1] && vector_fecha_nacimiento[i][0] > fecha_actual[0]))
                {
                    edad--;
                }

                // Verificar mayor y menor edad
                if (edad >= 18)
                {
                    if (edad > mayor_edad)
                    {
                        mayor_edad = edad;
                        estudiante_mayor_edad = vector_nombre[i];
                    }
                    else
                    {
                        if (edad < menor_edad)
                        {
                            menor_edad = edad;
                            estudiante_menor_edad = vector_nombre[i];
                        }
                    }
                }

                // Calcular promedios
                suma_notas = 0;
                for (int j = 0; j < vector_cantidad_notas[i]; j++)
                {
                    suma_notas += nota[i][j];
                }
                promedios[i] = suma_notas / vector_cantidad_notas[i];

                if (promedios[i] > promedio_alto)
                {
                    promedio_alto = promedios[i];
                    estudiante_promedio_alto = vector_nombre[i];
                }

                if (promedios[i] < promedio_bajo)
                {
                    promedio_bajo = promedios[i];
                    estudiante_promedio_bajo = vector_nombre[i];
                }

                if (vector_cantidad_notas[i] > mayor_cantidad_notas)
                {
                    mayor_cantidad_notas = vector_cantidad_notas[i];
                    estudiante_mayor_cantidad_notas = vector_nombre[i];
                }

                if (vector_cantidad_notas[i] < menor_cantidad_notas)
                {
                    menor_cantidad_notas = vector_cantidad_notas[i];
                    estudiante_menor_cantidad_notas = vector_nombre[i];
                }
            }

            // Reinicializar variables para actualizar estadísticas.
            cantidad_hombres = 0;
            cantidad_mujeres = 0;

            for (int i = 0; i < estudiantes; i++)
            {
                if (vector_genero[i] == "H")
                {
                    cantidad_hombres++;
                }
                else
                {
                    cantidad_mujeres++;
                }
            }

            system("clear");
            break;
        }

        case 3:
        { // Listado de estudiantes.
            cout << "\nLISTADO DE ESTUDIANTES." << endl;

            for (int i = 0; i < estudiantes; i++)
            {
                cout << i << ". " << vector_nombre[i] << " " << vector_apellido[i] << endl;
            }

            // Busqueda por cedula.
            cout << "\nINGRESE LA CEDULA DEL ESTUDIANTE A BUSCAR: ";
            cin >> cedula_buscada;

            system("clear");

            bool encontrado = false;

            for (int i = 0; i < estudiantes; i++)
            {
                if (vector_cedula[i] == cedula_buscada)
                {
                    encontrado = true;
                    cout << "\n- Nombre: " << vector_nombre[i] << endl;
                    cout << "- Apellido: " << vector_apellido[i] << endl;
                    cout << "- Fecha de nacimiento: " << vector_fecha_nacimiento[i][0] << "/" << vector_fecha_nacimiento[i][1] << "/" << vector_fecha_nacimiento[i][2] << endl;
                    cout << "- Genero: " << vector_genero[i] << endl;
                    cout << "- Cedula: " << vector_cedula[i] << endl;
                    cout << "- Cantidad de notas: " << vector_cantidad_notas[i] << endl;
                    cout << "- Notas: " << endl;
                    for (int j = 0; j < vector_cantidad_notas[i]; j++)
                    {
                        cout << "- " << nota[i][j] << endl;
                    }
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Estudiante no encontrado." << endl;
            }

            cout << "\n---------------------------------" << endl;
            cout << "(Para volver presione 1): ";
            cin >> volver2;

            system("clear");

            if (volver2 == 1)
            {
                break;
            }
            break;
        }

        case 4:
        { // Estadisticas.

            // Reiniciar contadores de hombres y mujeres
            cantidad_hombres = 0;
            cantidad_mujeres = 0;

            // Vectores para almacenar estudiantes con características similares
            vector<string> estudiantes_mayor_edad;
            vector<string> estudiantes_menor_edad;
            vector<string> estudiantes_mayor_cantidad_notas;
            vector<string> estudiantes_menor_cantidad_notas;
            vector<string> estudiantes_promedio_alto;
            vector<string> estudiantes_promedio_bajo;

            // Reiniciar valores
            mayor_edad = 0;
            menor_edad = 999;
            mayor_cantidad_notas = 0;
            menor_cantidad_notas = 999;
            promedio_alto = 0;
            promedio_bajo = 999;

            // Cálculo para cantidad de hombres y mujeres y otras estadísticas
            for (int i = 0; i < estudiantes; i++)
            {
                if (vector_genero[i] == "H")
                {
                    cantidad_hombres++;
                }
                else
                {
                    cantidad_mujeres++;
                }

                // Calcular edad
                int edad = fecha_actual[2] - vector_fecha_nacimiento[i][2];
                if (vector_fecha_nacimiento[i][1] > fecha_actual[1] ||
                    (vector_fecha_nacimiento[i][1] == fecha_actual[1] && vector_fecha_nacimiento[i][0] > fecha_actual[0]))
                {
                    edad--;
                }

                // Verificar mayor y menor edad
                if (edad > mayor_edad)
                {
                    mayor_edad = edad;
                    estudiantes_mayor_edad.clear();
                    estudiantes_mayor_edad.push_back(vector_nombre[i]);
                }
                else if (edad == mayor_edad)
                {
                    estudiantes_mayor_edad.push_back(vector_nombre[i]);
                }

                if (edad < menor_edad)
                {
                    menor_edad = edad;
                    estudiantes_menor_edad.clear();
                    estudiantes_menor_edad.push_back(vector_nombre[i]);
                }
                else if (edad == menor_edad)
                {
                    estudiantes_menor_edad.push_back(vector_nombre[i]);
                }

                // Calcular promedios
                double promedio = 0;
                for (int j = 0; j < vector_cantidad_notas[i]; j++)
                {
                    promedio += nota[i][j];
                }
                promedio /= vector_cantidad_notas[i];

                if (promedio > promedio_alto)
                {
                    promedio_alto = promedio;
                    estudiantes_promedio_alto.clear();
                    estudiantes_promedio_alto.push_back(vector_nombre[i]);
                }
                else if (promedio == promedio_alto)
                {
                    estudiantes_promedio_alto.push_back(vector_nombre[i]);
                }

                if (promedio < promedio_bajo)
                {
                    promedio_bajo = promedio;
                    estudiantes_promedio_bajo.clear();
                    estudiantes_promedio_bajo.push_back(vector_nombre[i]);
                }
                else if (promedio == promedio_bajo)
                {
                    estudiantes_promedio_bajo.push_back(vector_nombre[i]);
                }

                if (vector_cantidad_notas[i] > mayor_cantidad_notas)
                {
                    mayor_cantidad_notas = vector_cantidad_notas[i];
                    estudiantes_mayor_cantidad_notas.clear();
                    estudiantes_mayor_cantidad_notas.push_back(vector_nombre[i]);
                }
                else if (vector_cantidad_notas[i] == mayor_cantidad_notas)
                {
                    estudiantes_mayor_cantidad_notas.push_back(vector_nombre[i]);
                }

                if (vector_cantidad_notas[i] < menor_cantidad_notas)
                {
                    menor_cantidad_notas = vector_cantidad_notas[i];
                    estudiantes_menor_cantidad_notas.clear();
                    estudiantes_menor_cantidad_notas.push_back(vector_nombre[i]);
                }
                else if (vector_cantidad_notas[i] == menor_cantidad_notas)
                {
                    estudiantes_menor_cantidad_notas.push_back(vector_nombre[i]);
                }
            }

            cout << "\nESTADISTICAS." << endl;

            cout << "\n- Estudiantes mayor de edad: ";
            for (const auto &nombre : estudiantes_mayor_edad)
            {
                cout << nombre << " ";
            }
            cout << ", con la edad de " << mayor_edad << endl;

            cout << "- Estudiantes menor de edad: ";
            for (const auto &nombre : estudiantes_menor_edad)
            {
                cout << nombre << " ";
            }
            cout << ", con la edad de " << menor_edad << endl;

            cout << "- Estudiantes con mayor cantidad de notas procesadas: ";
            for (const auto &nombre : estudiantes_mayor_cantidad_notas)
            {
                cout << nombre << " ";
            }
            cout << ", con la cantidad de " << mayor_cantidad_notas << "." << endl;

            cout << "- Estudiantes con menor cantidad de notas procesadas: ";
            for (const auto &nombre : estudiantes_menor_cantidad_notas)
            {
                cout << nombre << " ";
            }
            cout << ", con la cantidad de " << menor_cantidad_notas << "." << endl;

            cout << "- Estudiantes con el promedio mas alto: ";
            for (const auto &nombre : estudiantes_promedio_alto)
            {
                cout << nombre << " ";
            }
            cout << ", con un promedio de " << promedio_alto << "." << endl;

            cout << "- Estudiantes con el promedio mas bajo: ";
            for (const auto &nombre : estudiantes_promedio_bajo)
            {
                cout << nombre << " ";
            }
            cout << ", con un promedio de " << promedio_bajo << "." << endl;

            cout << "- Cantidad de estudiantes hombres: " << cantidad_hombres << "." << endl;
            cout << "- Cantidad de estudiantes mujeres: " << cantidad_mujeres << "." << endl;

            cout << "\n---------------------------------" << endl;
            cout << "(Para volver presione 1): ";
            cin >> volver2;

            system("clear");

            if (volver2 == 1)
            {
                break;
            }
            break;
        }

#include <cmath> // Para usar la función ceil

        case 5:
        { // Reparticion de estudiantes en formato matriz.
            cout << "\nREPARTICION DE ESTUDIANTES." << endl;

            cout << "\n1. Salon unicamente de hombres." << endl;
            cout << "2. Salon unicamente de mujeres." << endl;
            cout << "3. Salon de aprobados." << endl;
            cout << "4. Salon de reprobados." << endl;
            cout << "5. Salon con todos los estudiantes." << endl;
            cout << "\nSELECCIONE LA MATRIZ A MOSTRAR: ";
            cin >> opt_matriz;

            system("clear");

            int indice_hombres = 0, indice_mujeres = 0, indice_aprobados = 0, indice_reprobados = 0, indice_todos = 0;

            for (int i = 0; i < estudiantes; i++)
            {
                // Salon unicamente de hombres
                if (vector_genero[i] == "H")
                {
                    salon_hombres[indice_hombres][0] = vector_nombre[i];
                    salon_hombres[indice_hombres][1] = vector_apellido[i];
                    indice_hombres++;
                }

                // Salon unicamente de mujeres
                if (vector_genero[i] == "M")
                {
                    salon_mujeres[indice_mujeres][0] = vector_nombre[i];
                    salon_mujeres[indice_mujeres][1] = vector_apellido[i];
                    indice_mujeres++;
                }

                // Calcular promedio
                double promedio = 0;
                for (int j = 0; j < vector_cantidad_notas[i]; j++)
                {
                    promedio += nota[i][j];
                }
                promedio /= vector_cantidad_notas[i];

                // Salon de aprobados
                if (promedio >= 10)
                {
                    salon_aprobados[indice_aprobados][0] = vector_nombre[i];
                    salon_aprobados[indice_aprobados][1] = vector_apellido[i];
                    indice_aprobados++;
                }
                else
                { // Salon de reprobados
                    salon_reprobados[indice_reprobados][0] = vector_nombre[i];
                    salon_reprobados[indice_reprobados][1] = vector_apellido[i];
                    indice_reprobados++;
                }

                // Salon con todos los estudiantes
                salon_todos[indice_todos][0] = vector_nombre[i];
                salon_todos[indice_todos][1] = vector_apellido[i];
                indice_todos++;
            }

            auto mostrar_matriz = [](string matriz[][2], int cantidad)
            {
                int size = ceil(sqrt(cantidad));
                cout << "Tamaño de la matriz: " << size << "x" << size << endl;
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        int index = i * size + j;
                        if (index < cantidad)
                        {
                            cout << matriz[index][0] << " " << matriz[index][1] << "\t";
                        }
                        else
                        {
                            cout << "XXXXX XXXXX\t";
                        }
                    }
                    cout << endl;
                }
            };

            switch (opt_matriz)
            {
            case 1:
            { // Salon unicamente de hombres
                cout << "\nSALON UNICAMENTE DE HOMBRES (Cantidad: " << indice_hombres << "):" << endl;
                mostrar_matriz(salon_hombres, indice_hombres);
                break;
            }
            case 2:
            { // Salon unicamente de mujeres
                cout << "\nSALON UNICAMENTE DE MUJERES (Cantidad: " << indice_mujeres << "):" << endl;
                mostrar_matriz(salon_mujeres, indice_mujeres);
                break;
            }
            case 3:
            { // Salon de aprobados
                cout << "\nSALON DE APROBADOS (Cantidad: " << indice_aprobados << "):" << endl;
                mostrar_matriz(salon_aprobados, indice_aprobados);
                break;
            }
            case 4:
            { // Salon de reprobados
                cout << "\nSALON DE REPROBADOS (Cantidad: " << indice_reprobados << "):" << endl;
                mostrar_matriz(salon_reprobados, indice_reprobados);
                break;
            }
            case 5:
            { // Salon con todos los estudiantes
                cout << "\nSALON CON TODOS LOS ESTUDIANTES (Cantidad: " << indice_todos << "):" << endl;
                mostrar_matriz(salon_todos, indice_todos);
                break;
            }
            default:
                cout << "Opcion no valida." << endl;
                break;
            }

            cout << "\n---------------------------------" << endl;
            cout << "(Para volver presione 1): ";
            cin >> volver2;

            system("clear");

            if (volver2 == 1)
            {
                break;
            }
            break;
        }

        case 6:
        { // Salir.
            cout << "\nDESEA CONTINUAR CON EL PROGRAMA? \nSi = 1,          No = 0." << endl;
            cin >> terminar;

            system("pause");
            system("clear");
            break;
        }
        }

    } while (terminar == 1);

    return 0;
}