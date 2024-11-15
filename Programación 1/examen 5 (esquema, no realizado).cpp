#include <iostream>
#include <string>

using namespace std;

// Definimos constantes para el número máximo de usuarios
const int MAX_USERS = 10;

// Funciones
void registrarUsuario(string nombres[], string usuarios[], string claves[], string cedulas[], double saldosDolares[], double saldosBolivares[], int &numUsuarios);
bool iniciarSesion(string usuarios[], string claves[], int numUsuarios, string &usuarioActual);
void menuOperaciones(string usuarios[], string claves[], string cedulas[], double saldosDolares[], double saldosBolivares[], int numUsuarios, string usuarioActual);
void transferencia(string usuarios[], string cedulas[], double saldosDolares[], int numUsuarios);
void deposito(double &saldo);
void retiro(double &saldo);
void pagoMovil(string usuarios[], double saldosDolares[], int numUsuarios);
void verInformacion(double saldoDolares, double saldoBolivares);

int main() {
    string nombres[MAX_USERS];
    string usuarios[MAX_USERS];
    string claves[MAX_USERS];
    string cedulas[MAX_USERS];
    double saldosDolares[MAX_USERS] = {0};
    double saldosBolivares[MAX_USERS] = {0};
    int numUsuarios = 0;
    string usuarioActual;

    while (true) {
        cout << "1. Registrar usuario" << endl;
        cout << "2. Iniciar sesión" << endl;
        cout << "3. Salir" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarUsuario(nombres, usuarios, claves, cedulas, saldosDolares, saldosBolivares, numUsuarios);
                break;
            case 2:
                if (iniciarSesion(usuarios, claves, numUsuarios, usuarioActual)) {
                    for (int i = 0; i < numUsuarios; i++) {
                        if (usuarios[i] == usuarioActual) {
                            menuOperaciones(usuarios, claves, cedulas, saldosDolares, saldosBolivares, numUsuarios, usuarioActual);
                            break;
                        }
                    }
                }
                break;
            case 3:
                cout << "Saliendo del sistema." << endl;
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
}

void registrarUsuario(string nombres[], string usuarios[], string claves[], string cedulas[], double saldosDolares[], double saldosBolivares[], int &numUsuarios) {
    if (numUsuarios < MAX_USERS) {
        cout << "Ingrese su nombre: ";
        cin >> nombres[numUsuarios];
        cout << "Ingrese su usuario: ";
        cin >> usuarios[numUsuarios];
        cout << "Ingrese su clave: ";
        cin >> claves[numUsuarios];
        cout << "Ingrese su cédula: ";
        cin >> cedulas[numUsuarios];
        saldosDolares[numUsuarios] = 0;
        saldosBolivares[numUsuarios] = 0;
        numUsuarios++;
        cout << "Usuario registrado exitosamente." << endl;
    } else {
        cout << "No se pueden registrar más usuarios." << endl;
    }
}

bool iniciarSesion(string usuarios[], string claves[], int numUsuarios, string &usuarioActual) {
    string usuario, clave;
    cout << "Ingrese su usuario: ";
    cin >> usuario;
    cout << "Ingrese su clave: ";
    cin >> clave;

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i] == usuario && claves[i] == clave) {
            usuarioActual = usuario;
            cout << "Inicio de sesión exitoso." << endl;
            return true;
        }
    }
    cout << "Usuario o clave incorrectos." << endl;
    return false;
}

void menuOperaciones(string usuarios[], string claves[], string cedulas[], double saldosDolares[], double saldosBolivares[], int numUsuarios, string usuarioActual) {
    int indexUsuario;
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i] == usuarioActual) {
            indexUsuario = i;
            break;
        }
    }

    while (true) {
        cout << "\nMenú de operaciones:" << endl;
        cout << "1. Transferencia" << endl;
        cout << "2. Depósito" << endl;
        cout << "3. Retiro" << endl;
        cout << "4. Pago móvil" << endl;
        cout << "5. Ver información" << endl;
        cout << "6. Salir" << endl;

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                transferencia(usuarios, cedulas, saldosDolares, numUsuarios);
                break;
            case 2:
                deposito(saldosDolares[indexUsuario]);
                break;
            case 3:
                retiro(saldosDolares[indexUsuario]);
                break;
            case 4:
                pagoMovil(usuarios, saldosDolares, numUsuarios);
                break;
            case 5:
                verInformacion(saldosDolares[indexUsuario], saldosBolivares[indexUsuario]);
                break;
            case 6:
                cout << "Saliendo del menú de operaciones." << endl;
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
}

void transferencia(string usuarios[], string cedulas[], double saldosDolares[], int numUsuarios) {
    string cedulaDestino;
    double monto;

    cout << "Ingrese la cédula del destinatario: ";
    cin >> cedulaDestino;
    cout << "Ingrese el monto a transferir: ";
    cin >> monto;

    for (int i = 0; i < numUsuarios; i++) {
        if (cedulas[i] == cedulaDestino) {
            if (monto > 0) {
                saldosDolares[i] += monto;
                cout << "Transferencia exitosa. Se han transferido " << monto << " dólares." << endl;
            } else {
                cout << "Monto inválido para la transferencia." << endl;
            }
            return;
        }
    }
    cout << "Cédula del destinatario no encontrada." << endl;
}

void deposito(double &saldo) {
    double monto;
    cout << "Ingrese el monto a depositar: ";
    cin >> monto;

    if (monto > 0) {
        saldo += monto;
        cout << "Depósito exitoso. Su nuevo saldo es: " << saldo << " dólares." << endl;
    } else {
        cout << "Monto inválido para el depósito." << endl;
    }
}

void retiro(double &saldo) {
    double monto;
    cout << "Ingrese el monto a retirar: ";
    cin >> monto;

    if (monto > 0 && monto <= saldo) {
        saldo -= monto;
        cout << "Retiro exitoso. Su nuevo saldo es: " << saldo << " dólares." << endl;
    } else {
        cout << "Monto inválido para el retiro." << endl;
    }
}

void pagoMovil(string usuarios[], double saldosDolares[], int numUsuarios) {
    string usuarioDestino;
    double monto;

    cout << "Ingrese el usuario del destinatario: ";
    cin >> usuarioDestino;
    cout << "Ingrese el monto a pagar: ";
    cin >> monto;

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i] == usuarioDestino) {
            if (monto > 0 && monto <= saldosDolares[i]) {
                saldosDolares[i] -= monto;
                cout << "Pago móvil exitoso. Se han pagado " << monto << " dólares." << endl;
            } else {
                cout << "Monto inválido para el pago móvil." << endl;
            }
            return;
        }
    }
    cout << "Usuario del destinatario no encontrado." << endl;
}

void verInformacion(double saldoDolares, double saldoBolivares) {
    cout << "Su saldo en dólares es: " << saldoDolares << " dólares." << endl;
    cout << "Su saldo en bolívares es: " << saldoBolivares << " bolívares." << endl;
}
