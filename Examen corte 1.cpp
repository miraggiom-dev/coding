#include <iostream>

using namespace std;

int main() {
    string nombre;
    double nota_uno, nota_dos, nota_tres;
    int dia, mes, ano;
    int dia_actual, mes_actual, ano_actual;

    // Introducir nombre y fecha de nacimiento

    cout << "Introduzca su nombre: ";
    cin >> nombre;

    cout << "\nIntroduzca su dia de nacimiento: ";
    cin >> dia;

    cout << "Introduzca su mes de su nacimiento: ";
    cin >> mes;

    cout << "Introduzca su ano de su nacimiento: ";
    cin >> ano;

    // Obtener fecha actual

    cout << "\nIngrese el dia actual: ";
    cin >> dia_actual;

    cout << "Ingrese el mes actual: ";
    cin >> mes_actual;

    cout << "Ingrese el ano actual: ";
    cin >> ano_actual;

    // Introducir las notas

    cout << "\nIngrese la primera nota: ";
    cin >> nota_uno;
    if (nota_uno < 0 || nota_uno > 20)
    {
        cout << "Error!!! La primera nota es invalida. Debe estar entre 0 y 20." << endl;
    }

    cout << "Ingrese la segunda nota: ";
    cin >> nota_dos;
    if (nota_dos < 0 || nota_dos > 20)
    {
        cout << "Error!!! La segunda nota es invalida. Debe estar entre 0 y 20." << endl;
    }

    cout << "Ingrese la tercera nota: ";
    cin >> nota_tres;
    if (nota_tres < 0 || nota_tres > 20)
    {
        cout << "Error!!! La tercera nota es invalida. Debe estar entre 0 y 20." << endl;
    }

    // Determinar si la persona es mayor o menor de edad

    if (ano_actual - ano > 18 || (ano_actual - ano == 18 && (mes_actual > mes || (mes_actual == mes && dia_actual >= dia))))
    {
        cout << "\n" << nombre << ", usted es mayor de edad." << endl;
    }
    else
    {
        cout << "\n" << nombre << ", usted es menor de edad." << endl;
    }

    // Calcular el promedio en el sistema venezolano y americano

    double promedioV = (nota_uno + nota_dos + nota_tres) / 3;
    double promedioA = promedioV / 2;
    string promedioAL;
    
    if (promedioA >= 0 && promedioA < 6)
    {
        promedioAL = "F";
    }
    else if (promedioA >= 6 && promedioA < 7)
    {
        promedioAL = "D";
    }
    else if (promedioA >= 7 && promedioA < 8)
    {
        promedioAL = "C";
    }
    else if (promedioA >= 8 && promedioA < 9)
    {
        promedioAL = "B";
    }
    else if (promedioA >= 9 && promedioA <= 10)
    {
        promedioAL = "A";
    }

    if ((nota_uno < 0 || nota_uno > 20) || (nota_dos < 0 || nota_dos > 20) || (nota_tres < 0 || nota_tres > 20))
    {
        cout << "\nError!!! Las notas son invalidas. Deben estar entre 0 y 20." << endl;
    }
    else if (promedioV >= 9.5 && promedioV <= 20 && promedioA >= 6 && promedioA <= 10) {
    	cout << "\nEl promedio venezolano es: " << promedioV << " y el americano es: " << promedioA << " = " << promedioAL << endl;
        	cout << "Aprobado!!!" << endl;
  	}
  
  	if (promedioV >= 0 && promedioV < 9.5 && promedioA >= 0 && promedioA < 5)
    {
    	cout << "Desaprobado. :(" << endl;
    }

    // Convertir las notas a formato americano (numerico)

    double nota_unoA = nota_uno / 2;
    double nota_dosA = nota_dos / 2;
    double nota_tresA = nota_tres / 2;

    // Convertir las notas a formato americano (letras)

    string nota_unoL, nota_dosL, nota_tresL;

    if (nota_unoA >= 0 && nota_unoA < 6)
    {
        nota_unoL = "F";
    }
    else if (nota_unoA >= 6 && nota_unoA < 7)
    {
        nota_unoL = "D";
    }
    else if (nota_unoA >= 7 && nota_unoA < 8)
    {
        nota_unoL = "C";
    }
    else if (nota_unoA >= 8 && nota_unoA < 9)
    {
        nota_unoL = "B";
    }
    else if (nota_unoA >= 9 && nota_unoA <= 10)
    {
        nota_unoL = "A";
    }

    if (nota_dosA >= 0 && nota_dosA < 6)
    {
        nota_dosL = "F";
    }
    else if (nota_dosA >= 6 && nota_dosA < 7)
    {
        nota_dosL = "D";
    }
    else if (nota_dosA >= 7 && nota_dosA < 8)
    {
        nota_dosL = "C";
    }
    else if (nota_dosA >= 8 && nota_dosA < 9)
    {
        nota_dosL = "B";
    }
    else if (nota_dosA >= 9 && nota_dosA <= 10)
    {
        nota_dosL = "A";
    }

    if (nota_tresA >= 0 && nota_tresA < 6)
    {
        nota_tresL = "F";
    }
    else if (nota_tresA >= 6 && nota_tresA < 7)
    {
        nota_tresL = "D";
    }
    else if (nota_tresA >= 7 && nota_tresA < 8)
    {
        nota_tresL = "C";
    }
    else if (nota_tresA >= 8 && nota_tresA < 9)
    {
        nota_tresL = "B";
    }
    else if (nota_tresA >= 9 && nota_tresA <= 10)
    {
        nota_tresL = "A";
    }
    
    // Mostrar las notas en formato americano (letras y numeros)

    cout << "\nLa primera nota en formato americano numerico es: " << nota_unoA << " y en formato americano de letras es: " << nota_unoL << endl;
    cout << "La segunda nota en formato americano numerico es: " << nota_dosA << " y en formato americano de letras es: " << nota_dosL << endl;
    cout << "La tercera nota en formato americano numerico es: " << nota_tresA << " y en formato americano de letras es: " << nota_tresL << endl;

    // Encontrar la nota mas alta y la mas baja

    double mas_alta = nota_uno;
    if (nota_dos > mas_alta)
    {
        mas_alta = nota_dos;
    }
    if (nota_tres > mas_alta)
    {
        mas_alta = nota_tres;
    }

    cout << "\nLa nota mas alta es: " << mas_alta << endl;

    double mas_baja = nota_uno;
    if (nota_dos < mas_baja)
    {
        mas_baja = nota_dos;
    }
    if (nota_tres < mas_baja)
    {
        mas_baja = nota_tres;
    }

    cout << "La nota mas baja es: " << mas_baja << endl;

    // Determinar si las notas son iguales

    if (nota_uno == nota_dos && nota_dos == nota_tres)
    {
        cout << "\nLas tres notas son iguales." << endl;
    }
    else if (nota_uno == nota_dos)
    {
        cout << "\nLa primera y segunda nota son iguales." << endl;
    }
    else if (nota_dos == nota_tres)
    {
        cout << "\nLa segunda y tercera nota son iguales." << endl;
    }
    else if (nota_uno == nota_tres)
    {
        cout << "\nLa primera y tercera nota son iguales." << endl;
    }

    // Calcular el signo zodiacal

    if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 20))
    {
        cout << "\nSu signo zodiacal es Aries." << endl;
    }
    else if ((mes == 4 && dia >= 21) || (mes == 5 && dia <= 20))
    {
        cout << "\nSu signo zodiacal es Tauro." << endl;
    }
    else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 21))
    {
        cout << "\nSu signo zodiacal es Geminis." << endl;
    }
    else if ((mes == 6 && dia >= 22) || (mes == 7 && dia <= 22))
    {
        cout << "\nSu signo zodiacal es Cancer." << endl;
    }
    else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 23))
    {
        cout << "\nSu signo zodiacal es Leo." << endl;
    }
    else if ((mes == 8 && dia >= 24) || (mes == 9 && dia <= 23))
    {
        cout << "\nSu signo zodiacal es Virgo." << endl;
    }
    else if ((mes == 9 && dia >= 24) || (mes == 10 && dia <= 23))
    {
        cout << "\nSu signo zodiacal es Libra." << endl;
    }
    else if ((mes == 10 && dia >= 24) || (mes == 11 && dia <= 22))
    {
        cout << "\nSu signo zodiacal es Escorpio." << endl;
    }
    else if ((mes == 11 && dia >= 23) || (mes == 12 && dia <= 21))
    {
        cout << "\nSu signo zodiacal es Sagitario." << endl;
    }
    else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 20))
    {
        cout << "\nSu signo zodiacal es Capricornio." << endl;
    }
    else if ((mes == 1 && dia >= 21) || (mes == 2 && dia <= 19))
    {
        cout << "\nSu signo zodiacal es Acuario." << endl;
    }
    else if ((mes == 2 && dia >= 20) || (mes == 3 && dia <= 20))
    {
        cout << "\nSu signo zodiacal es Piscis." << endl;
    }
    
}
