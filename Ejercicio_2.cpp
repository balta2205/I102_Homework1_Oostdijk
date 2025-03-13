#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void logMessage(string msj, string tipo);

int main(){

    string tipos[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
    int num;
    string msj;
    string tipo;

    ofstream outFile("log.txt");

    while (true){
        do{
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
        cin >> msj;

        tipo = tipos[num - 1];

        logMessage(msj, tipo);
    }
}

void logMessage(string msj, string tipo){
    ofstream outFile("log.txt", ios::app);
    outFile << "[" << tipo << "] <" << msj << "> " << endl;
    outFile.close();
}