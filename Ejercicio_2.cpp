#include <iostream>
#include <fstream>
#include <string>
#include <ctime>    
#include <stdexcept>  

using namespace std;

void logMessage(ofstream& logFile, const string& msj, const string& tipo);
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& archivo, int linea);
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& nombre_usuario);

int main() {
    string tipos[6] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL", "SECURITY"};
    int num;
    string msj;
    string tipo;
    string nombre_usuario;

    ofstream outFile("log.txt", ios::app);

    if (!outFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << std::endl;
        return 1;
    }

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
            cout << "[7] FINALIZAR." << endl;
            cout << endl;
            cout << "Opcion: "; 
            cin >> num;
        } while (num < 1 || num > 7);

        if (num == 7) {
            outFile.close();
            break;
        }
        if (num == 6) {
            string op[2] = {"Access Granted", "Access Denied"};
            int num_2;
            cout << "Ingrese el mensaje de acceso (Access Granted [1] / Access Denied [2]): ";
            cin >> num_2;
            if(num_2 < 1 || num_2 > 2){
                cout << "Opcion no valida." << endl;
                continue;
            }
            msj = op[num_2 - 1];
            cout << "Ingrese el nombre de usuario: ";
            getline(cin, nombre_usuario);
            logMessage(outFile, msj, "SECURITY", nombre_usuario);
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
