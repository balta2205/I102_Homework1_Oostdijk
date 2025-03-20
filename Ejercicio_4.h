#ifndef EJERCICIO_4_H
#define EJERCICIO_4_H

#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>

// Función recursiva en tiempo de ejecución
bool compararRecursivo(const char* t1, const char* t2, int index);

// Función recursiva en tiempo de compilación
constexpr bool compararEnTiempoDeCompilacion(const char* t1, const char* t2, int index);


#endif