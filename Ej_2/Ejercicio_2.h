#ifndef EJERCICIO_2_H
#define EJERCICIO_2_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>    
#include <stdexcept>  

using namespace std;

void logMessage(ofstream& logFile, const string& msj, const string& tipo);
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& archivo, int linea);
void logMessage(ofstream& logFile, const string& msj, const string& tipo, const string& nombre_usuario);

#endif