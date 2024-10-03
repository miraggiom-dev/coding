#include <iostream>

using namespace std;

int main() {

    string nombre, estudiante_mayor_nota, estudiante_menor_nota, estudiante_mayor_edad, estudiante_menor_edad, estudiante_mayor_cantidad_notas, estudiante_menor_cantidad_notas;
    int cantidad_estudiantes, dia, mes, ano, dia_actual, mes_actual, ano_actual, edad, dia_mayor_edad, dia_menor_edad, mes_mayor_edad, mes_menor_edad;
    int mayor_edad = 0, menor_edad = 100, cantidad_notas, nota, suma_notas, mayor_nota = 0, menor_nota = 100, cantidad_notas_procesadas = 0, mayor_cantidad_notas = 0, menor_cantidad_notas = 100, cantidad_notas_erroneas = 0;

    // Inicializar introduciendo cantidad de estudiantes y sus respectivos datos

    cout << "Introduzca la cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;

    for (int i = 0; i < cantidad_estudiantes; i++) {
        cout << "\nIntroduzca el nombre del estudiante: ";
        cin >> nombre;

        cout << "Ingrese el día de nacimiento (DD/MM/AAAA)." << endl;
        cout << "Día: ";
        cin >> dia;

        cout << "Mes: ";
        cin >> mes;

        cout << "Año: ";
        cin >> ano;


        cout << "\nIngrese la cantidad de notas: ";
        cin >> cantidad_notas;
        suma_notas = 0;

        for (int j = 0; j < cantidad_notas; j++) {
            while (true) {
                cout << "Introduzca la nota del estudiante " << nombre << ": ";
                cin >> nota;

                if (nota < 0 || nota > 20) {
                    cout << "Nota inválida. Por favor, introduzca una nota entre 0 y 20." << endl;
                    cantidad_notas_erroneas++;
                } else {
                    suma_notas += nota;
                    cantidad_notas_procesadas++;

                    if (nota > mayor_nota) {
                        mayor_nota = nota;
                        estudiante_mayor_nota = nombre;
                    }
                    if (nota < menor_nota) {
                        menor_nota = nota;
                        estudiante_menor_nota = nombre;
                    }
                    break;
                }
            }
        }

        if (cantidad_notas > mayor_cantidad_notas) {
            mayor_cantidad_notas = cantidad_notas;
            estudiante_mayor_cantidad_notas = nombre;
        }
        if (cantidad_notas < menor_cantidad_notas) {
            menor_cantidad_notas = cantidad_notas;
            estudiante_menor_cantidad_notas = nombre;
        }

        // Obtener fecha actual

        cout << "\nIngrese la fecha actual." << endl;
        cout << "Día: ";
        cin >> dia_actual;

        cout << "Mes: ";
        cin >> mes_actual;

        cout << "Año: ";
        cin >> ano_actual;

        // Calcular edad

        edad = ano_actual - ano;
        if (mes_actual < mes || (mes_actual == mes && dia_actual < dia)) {
            edad--;
        }

        if (edad > mayor_edad || (edad == mayor_edad && (mes < mes_mayor_edad || (mes == mes_mayor_edad && dia < dia_mayor_edad)))) {
            mayor_edad = edad;
            mes_mayor_edad = mes;
            dia_mayor_edad = dia;
            estudiante_mayor_edad = nombre;
        }
        if (edad < menor_edad || (edad == menor_edad && (mes > mes_menor_edad || (mes == mes_menor_edad && dia > dia_menor_edad)))) {
            menor_edad = edad;
            mes_menor_edad = mes;
            dia_menor_edad = dia;
            estudiante_menor_edad = nombre;
        }
    }

    // Resultados

    cout << "\nEl estudiante con la mayor nota es: " << estudiante_mayor_nota << " con " << mayor_nota << "." << endl;
    cout << "El estudiante con la menor nota es: " << estudiante_menor_nota << " con " << menor_nota << "." << endl;
    cout << "\nEl estudiante con la mayor edad es: " << estudiante_mayor_edad << " con " << mayor_edad << " años." << endl;
    cout << "El estudiante de menor edad es: " << estudiante_menor_edad << " con " << menor_edad << " años." << endl;
    cout << "\nLa cantidad de notas procesadas fue: " << cantidad_notas_procesadas << "."  << endl;
    cout << "La cantidad de estudiantes procesados fue: " << cantidad_estudiantes << "." << endl;
    cout << "\nEl estudiante con más notas procesadas es: " << estudiante_mayor_cantidad_notas << " con " << mayor_cantidad_notas << " notas." << endl;
    cout << "El estudiante con menos notas procesadas es: " << estudiante_menor_cantidad_notas << " con " << menor_cantidad_notas << " notas." << endl;
    cout << "\nLa cantidad de notas erróneas fue: " << cantidad_notas_erroneas << "." << endl;

}