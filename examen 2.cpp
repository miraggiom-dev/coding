#include <iostream>

using namespace std;

int main() {

    bool SYS = true;
    string nombre, tecla, N = "N", S = "S", promedioAL;
    string estudiante_mayor_nota, estudiante_menor_nota, estudiante_mayor_cantidad_notas, estudiante_menor_cantidad_notas;
    string estudiante_mayor_edad, estudiante_menor_edad, estudiante_mayor_promedio, estudiante_menor_promedio;
    int dia, mes, ano, dia_actual, mes_actual, ano_actual;
    int edad, dia_mayor_edad, dia_menor_edad, mes_mayor_edad, mes_menor_edad, cantidad_estudiantes, cantidad_notas;
    int mayor_edad = 0, menor_edad = 100, cantidad_notas_procesadas = 0, mayor_cantidad_notas = 0, menor_cantidad_notas = 100, cantidad_notas_erroneas = 0;
    double nota, suma_notas = 0, mayor_nota = 0, menor_nota = 100, mayor_promedioV = -1, menor_promedioV = 21, mayor_promedioA = -1, menor_promedioA = 21;

    do {
        // Inicializar introduciendo cantidad de estudiantes

        cout << "Introduzca la cantidad de estudiantes: ";
        cin >> cantidad_estudiantes;

        // Obtener la fecha actual

        cout << "\nIngrese la fecha actual." << endl;
        cout << "Día: ";
        cin >> dia_actual;

        cout << "Mes: ";
        cin >> mes_actual;

        cout << "Año: ";
        cin >> ano_actual;

        // Procesar estudiantes con sus respectivos datos

        for (int i = 0; i < cantidad_estudiantes; i++)
        {
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

            for (int j = 0; j < cantidad_notas; j++)
            {
                while (true)
                {
                    cout << "Introduzca la nota del estudiante " << nombre << ": ";
                    cin >> nota;

                    if (nota < 0 || nota > 20) {
                        cout << "Nota inválida. Por favor, introduzca una nota entre 0 y 20." << endl;
                        cantidad_notas_erroneas++;
                    }
                    else {
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

            // Calcular promedio

            double promedioV = suma_notas / cantidad_notas;
            double promedioA = promedioV / 2;

            if (promedioV > mayor_promedioV) {
                mayor_promedioV = promedioV;
                estudiante_mayor_promedio = nombre;
            }
            if (promedioV < menor_promedioV) {
                menor_promedioV = promedioV;
                estudiante_menor_promedio = nombre;
            }

            if (promedioA > mayor_promedioA) {
                mayor_promedioA = promedioA;
                estudiante_mayor_promedio = nombre;
            }
            if (promedioA < menor_promedioA) {
                menor_promedioA = promedioA;
                estudiante_menor_promedio = nombre;
            }

            if (promedioA >= 0 && promedioA < 6) {
                promedioAL = "F";
            }
            else if (promedioA >= 6 && promedioA < 7) {
                promedioAL = "D";
            }
            else if (promedioA >= 7 && promedioA < 8) {
                promedioAL = "C";
            }
            else if (promedioA >= 8 && promedioA < 9) {
                promedioAL = "B";
            }
            else if (promedioA >= 9 && promedioA <= 10) {
                promedioAL = "A";
            }
        }

        // Resultados

        cout << "\nResultados: " << endl;

        cout << "\nEl estudiante con la mayor nota es: " << estudiante_mayor_nota << " con " << mayor_nota << "." << endl;
        cout << "El estudiante con la menor nota es: " << estudiante_menor_nota << " con " << menor_nota << "." << endl;
        cout << "\nEl estudiante con el mayor promedio es: " << estudiante_mayor_promedio << " con " << mayor_promedioV << ", y en sistema americano: " << mayor_promedioA << " = " << promedioAL << endl;
        cout << "El estudiante con el menor promedio es: " << estudiante_menor_promedio << " con " << menor_promedioV << ", y en sistema americano: " << menor_promedioA << " = " << promedioAL << endl;
        cout << "\nEl estudiante con la mayor edad es: " << estudiante_mayor_edad << " con " << mayor_edad << " años." << endl;
        cout << "El estudiante de menor edad es: " << estudiante_menor_edad << " con " << menor_edad << " años." << endl;
        cout << "\nEl estudiante con más notas procesadas es: " << estudiante_mayor_cantidad_notas << " con " << mayor_cantidad_notas << " notas." << endl;
        cout << "El estudiante con menos notas procesadas es: " << estudiante_menor_cantidad_notas << " con " << menor_cantidad_notas << " notas." << endl;
        cout << "\nLa cantidad de notas procesadas fue: " << cantidad_notas_procesadas << "." << endl;
        cout << "La cantidad de estudiantes procesados fue: " << cantidad_estudiantes << "." << endl;
        cout << "La cantidad de notas erróneas fue: " << cantidad_notas_erroneas << "." << endl;

        cout << "\nDesea continuar? \nNo = N, Sí = S. " << endl;
        cin >> tecla;

        if (tecla == N) {
            SYS = false;
        }
        else {
            SYS = true;
        }

        system("pause");
        system("cls");

    } while (SYS);

}