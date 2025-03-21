#include "Ejercicio_2.h"

using namespace std;

/* En este programa, se simula un sistema de registro de logs, donde el usuario puede ingresar diferentes tipos de mensajes 
   con diversas severidades. Los tipos de mensajes incluyen: DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY, y SIMULATED_ERROR.
   
   El usuario tiene un menú interactivo que le permite elegir el tipo de mensaje, ingresar el contenido y, en algunos casos, 
   proporcionar información adicional, como el nombre de usuario en el caso de los mensajes de tipo SECURITY, o los detalles 
   del archivo y la línea en el caso de los mensajes ERROR.

   Los mensajes son registrados en un archivo de log (`log.txt`) con la fecha y hora actuales. Además, se implementa un manejo 
   de excepciones para simular y capturar un error durante la ejecución, y registrar este evento en el archivo de log.

   Este programa demuestra el uso de funciones sobrecargadas para registrar distintos tipos de mensajes, y utiliza excepciones 
   para manejar errores de manera eficiente.
*/


int main() {
    // Definir los tipos de severidad de los mensajes
    string tipos[7] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL", "SECURITY", "SIMULATED_ERROR"};
    int num;
    string msj;
    string tipo;
    string nombre_usuario;

    // Abrir archivo de log en modo append
    ofstream outFile("log.txt", ios::app);

    if (!outFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return 1;
    }

    try {
        while (true) {
            // Menú de opciones
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

            // Si el usuario selecciona finalizar, se cierra el archivo y termina el programa
            if (num == 8) {
                outFile.close();
                break;
            }

            // Opción para registrar acceso de usuario (tipo SECURITY)
            if (num == 6) {
                string op[2] = {"Access Granted", "Access Denied"};
                int num_2;
                cout << "Ingrese el mensaje de acceso (Access Granted [1] / Access Denied [2]): ";
                cin >> num_2;
                if (num_2 < 1 || num_2 > 2) {
                    cout << "Opcion no valida." << endl;
                    continue;
                }
                msj = op[num_2 - 1];  // Asignar el mensaje según la opción seleccionada
                cout << "Ingrese el nombre de usuario: ";
                cin.ignore();
                getline(cin, nombre_usuario);
                logMessage(outFile, msj, "SECURITY", nombre_usuario);
            } 
            // Opción para simular un error (se genera una excepción)
            else if (num == 7) {
                throw runtime_error("Error simulado para pruebas de captura de excepciones.");
            }
            else {
                // Para otras opciones, se pide al usuario ingresar un mensaje
                cout << "Ingrese el mensaje a registrar: ";
                cin.ignore(); 
                getline(cin, msj);

                tipo = tipos[num - 1];  // Asignar el tipo de mensaje basado en la opción seleccionada

                // Si el tipo es ERROR, se pide información adicional sobre archivo y línea
                if (num == 4) {
                    string archivo;
                    int linea;
                    cout << "Ingrese el archivo donde ocurrió el error: ";
                    getline(cin, archivo);
                    cout << "Ingrese la línea de código donde ocurrió el error: ";
                    cin >> linea;
                    logMessage(outFile, msj, tipo, archivo, linea);
                } else {
                    // Para otros tipos, solo se registra el mensaje y tipo
                    logMessage(outFile, msj, tipo);
                }
            }
        }
    } catch (const exception& e) {
        // Manejo de excepciones, registrando el error en el log
        logMessage(outFile, "Error en tiempo de ejecución: " + string(e.what()), "SIMULATED_ERROR");
        cerr << "Ocurrió un error en tiempo de ejecución: " << e.what() << endl;
        return 1;
    }
    return 0;
}

// Función para registrar mensajes generales
void logMessage(ofstream& logFile, const string& msj, const string& tipo) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);  // Obtener el tiempo actual
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));  // Formatear la fecha

    // Escribir el mensaje en el archivo de log
    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> " << endl;
}

// Función para registrar mensajes de tipo ERROR con archivo y línea
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& archivo, int linea) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);  // Obtener el tiempo actual
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    // Escribir el mensaje con detalles de archivo y línea
    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> (Archivo: " << archivo << ", Línea: " << linea << ") " << endl;
}

// Función para registrar mensajes de tipo SECURITY con nombre de usuario
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& nombre_usuario) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);  // Obtener el tiempo actual
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    // Escribir el mensaje con el nombre de usuario
    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> (Usuario: " << nombre_usuario << ") " << endl;
}
