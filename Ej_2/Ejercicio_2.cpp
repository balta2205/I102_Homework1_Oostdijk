#include "Ejercicio_2.h"

using namespace std;

int main() {
    string tipos[7] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL", "SECURITY", "SIMULATED_ERROR"};
    int num;
    string msj;
    string tipo;
    string nombre_usuario;

    ofstream outFile("log.txt", ios::app);

    if (!outFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << std::endl;
        return 1;
    }

    try {
        while (true) {
            do {
                num = 0;
                cout << "Ingrese la severidad/importancia del mensaje:" << endl;
                cout << "[1] DEBUG." << endl;
                cout << "[2] INFO." << endl;
                cout << "[3] WARNING." << endl;
                cout << "[4] ERROR." << endl;
                cout << "[5] CRITICAL." << endl;
                cout << "[6] ACCESO DE USUARIO." << endl;
                cout << "[7] SIMULAR ERROR." << endl;
                cout << "[8] FINALIZAR." << endl;
                cout << endl;
                cout << "Opcion: "; 
                cin >> num;
            } while (num < 1 || num > 8);

            if (num == 8) {
                outFile.close();
                break;
            }
            if (num == 6) {
                string op[2] = {"Access Granted", "Access Denied"};
                int num_2;
                cout << "Ingrese el mensaje de acceso (Access Granted [1] / Access Denied [2]): ";
                cin >> num_2;
                if (num_2 < 1 || num_2 > 2) {
                    cout << "Opcion no valida." << endl;
                    continue;
                }
                msj = op[num_2 - 1];
                cout << "Ingrese el nombre de usuario: ";
                cin.ignore();
                getline(cin, nombre_usuario);
                logMessage(outFile, msj, "SECURITY", nombre_usuario);
            } 
            else if (num == 7) {
                throw runtime_error("Error simulado para pruebas de captura de excepciones.");
            }
            else {
                cout << "Ingrese el mensaje a registrar: ";
                cin.ignore(); 
                getline(cin, msj);

                tipo = tipos[num - 1];

                if (num == 4) {
                    string archivo;
                    int linea;
                    cout << "Ingrese el archivo donde ocurrió el error: ";
                    getline(cin, archivo);
                    cout << "Ingrese la línea de código donde ocurrió el error: ";
                    cin >> linea;
                    logMessage(outFile, msj, tipo, archivo, linea);
                } else {
                    logMessage(outFile, msj, tipo);
                }
            }
        }
    } catch (const exception& e) {
        logMessage(outFile, "Error en tiempo de ejecución: " + string(e.what()), "SIMULATED_ERROR");
        cerr << "Ocurrió un error en tiempo de ejecución: " << e.what() << endl;
        return 1;
    }
    return 0;
}

// Sobrecarga de funciones logMessage.

// logMessage para mensajes de tipo DEBUG, INFO, WARNING y CRITICAL.
void logMessage(ofstream& logFile, const string& msj, const string& tipo) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> " << endl;
}

// logMessage para mensajes de tipo ERROR.
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& archivo, int linea) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> (Archivo: " << archivo << ", Línea: " << linea << ") " << endl;
}

// logMessage para mensajes de tipo SECURITY.
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& nombre_usuario) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> (Usuario: " << nombre_usuario << ") " << endl;
}