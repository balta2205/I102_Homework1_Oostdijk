#include <iostream>
#include <fstream>
#include <string>
#include <ctime>	
using namespace std;

void logMessage(ofstream& logFile, const string& msj, const string& tipo);

int main(){

    string tipos[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
    int num;
    string msj;
    string tipo;

    ofstream outFile("log.txt", ios::app);

    if (!outFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << std::endl;
        return 1;
    }

    while (true){
        do{
            num = 0;
            cout << "Ingrese la severidad/importancia del mensaje:" << endl;
            cout << "[1] DEBUG." << endl;
            cout << "[2] INFO." << endl;
            cout << "[3] WARNING." << endl;
            cout << "[4] ERROR." << endl;
            cout << "[5] CRITICAL." << endl;
            cout << "[6] FINALIZAR." << endl;
            cout << "Opcion: "; 
            cin >> num;
        }while(num < 1 || num > 6);
        
        if(num == 6){
            outFile.close();
            break;
        }
        
        cout << "Ingrese el mensaje a registrar: ";
        cin.ignore(); 
        getline(cin, msj);

        tipo = tipos[num - 1];

        logMessage(outFile, msj, tipo);
        num = 0;
    }
}

void logMessage(ofstream& logFile, const string& msj, const string& tipo) {
    if (!logFile) {
        cerr << "Error: No se pudo abrir el archivo de log." << endl;
        return;
    }

    time_t t = std::time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&t));

    // Escribir en el archivo
    logFile << "[" << buffer << "] [" << tipo << "] <" << msj << "> " << endl;
}