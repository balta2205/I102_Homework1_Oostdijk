#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>

using namespace std;

bool compararRecursivo(const char* t1, const char* t2, int index);

int main(){
    const char* t1 = "Este es un texto de prueba que tiene exactamente sesenta y cuatro.";
    const char* t2 = "Este es un texto de prueba que tiene exactamente sesenta y cuatro.";
    
    auto start = chrono::high_resolution_clock::now();
    bool result = compararRecursivo(t1, t2, 0);
    cout << "Los textos son iguales: " << (result ? "true" : "false") << endl;
    auto end = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "A mi compararRecursivo le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
}

bool compararRecursivo(const char* t1, const char* t2, int index){
    if(t1[index] == '\0' && t2[index] == '\0') return true;
    if(t1[index] != t2[index]) return false;
    return compararRecursivo(t1, t2, index + 1);
}

