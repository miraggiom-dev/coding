#include <iostream>
#include <string>

using namespace std;

int max_palabras = 100;

string ingresarTexto() {
	
    string texto;
    
    cout << "Ingrese el texto: ";
    cin.ignore();
    getline(cin, texto);
    
    system("cls");
    
    return texto;
}

int ingresarPalabrasCensurar(string palabras[]) {
	
    int numero_palabras;
    
    cout << "Ingrese la cantidad de palabras a censurar: ";
    cin >> numero_palabras;
    cin.ignore();
    
    for (int i = 0; i < numero_palabras; i++) {
        cout << "Ingrese la palabra " << (i + 1) << ": ";
        getline(cin, palabras[i]);
    }
    
    system("cls");
    
    return numero_palabras;
}

string mostrarTextoCensurado(string texto, string palabras[], int numero_palabras) {
	
    for (int i = 0; i < numero_palabras; i++) {
    	
        string palabra = palabras[i];
        size_t pos = 0;

        while ((pos = texto.find(palabra, pos)) != string::npos) {
            
            bool es_inicio = (pos == 0 || texto[pos - 1] == ' ' || texto[pos - 1] == '.' || texto[pos - 1] == ',' || texto[pos - 1] == '!' || texto[pos - 1] == '?');
            bool es_fin = (pos + palabra.length() == texto.length() || texto[pos + palabra.length()] == ' ' || texto[pos + palabra.length()] == '.' || texto[pos + palabra.length()] == ',' || texto[pos + palabra.length()] == '!' || texto[pos + palabra.length()] == '?');

            if (es_inicio && es_fin) {
                texto.replace(pos, palabra.length(), "*");
                pos += 1;
            } else {
                pos += palabra.length();
            }
        }
    }
    
    system("cls");

    return texto;
}

void mostrarEstadisticas(string texto, string palabras[], int numero_palabras) {
	
    int conteos[max_palabras] = {0};

    for (int i = 0; i < numero_palabras; i++) {
    	
        string palabra = palabras[i];
        size_t pos = 0;
        
        while ((pos = texto.find(palabra, pos)) != string::npos) {
            
            bool es_inicio = (pos == 0 || texto[pos - 1] == ' ' || texto[pos - 1] == '.' || texto[pos - 1] == ',' || texto[pos - 1] == '!' || texto[pos - 1] == '?');
            bool es_fin = (pos + palabra.length() == texto.length() || texto[pos + palabra.length()] == ' ' || texto[pos + palabra.length()] == '.' || texto[pos + palabra.length()] == ',' || texto[pos + palabra.length()] == '!' || texto[pos + palabra.length()] == '?');

            if (es_inicio && es_fin) {
                conteos[i]++;
            }
            pos += palabra.length();
        }
    }

    cout << "Estadisticas de palabras censuradas:" << endl;
    
    for (int i = 0; i < numero_palabras; i++) {
        cout << palabras[i] << ": " << conteos[i] << " veces" << endl;
    }

}

void pausar() {
	
    cout << "Presione Enter para continuar..." << endl;
    cin.ignore();
}

int main() {
	
    string texto;
    string palabras[max_palabras];
    int numero_palabras = 0;
    int opcion;

    do {
        cout << "          Menu:" << endl;
        cout << "\n1. Ingresar texto" << endl;
        cout << "2. Ingresar palabras a censurar" << endl;
        cout << "3. Mostrar texto con palabras censuradas" << endl;
        cout << "4. Estadisticas" << endl;
        cout << "5. Salir" << endl;
        
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        
        system("cls");

        switch (opcion) {
        	
            case 1:
                texto = ingresarTexto();
                break;
                
            case 2:
                numero_palabras = ingresarPalabrasCensurar(palabras);
                break;
                
            case 3:
                cout << "Texto censurado: " << mostrarTextoCensurado(texto, palabras, numero_palabras) << endl;
                system("pause");
                system("cls");
                break;
                
            case 4:
                mostrarEstadisticas(texto, palabras, numero_palabras);
                system("pause");
                system("cls");
                break;
                
            case 5:
                cout << "Saliendo..." << endl;
                break;
                
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);

    return 0;
}
