#include "Ejercicio_4.h"

using namespace std;

/* Comparo dos textos de manera recusiva utilizando variables de tipo const char*, 
   gracias a esto puedo iterar sobre los caracteres de los textos de manera recursiva.

   De esta manera, itero sobre cada caracter de los dos textos, y me detengo en el caso en que, si un character es diferente,
   retorno false, y si ambos caracteres son '\0' (fin de cadena), retorno true. si no se cumple ninguna de las condiciones anteriores,
   llamo a la función recursiva con el siguiente índice.

   Por otro lado, tambien se implementa una función recursiva en tiempo de compilación, la cual se resuelve durante la compilación.
   En este caso, se utiliza la palabra clave constexpr, la cual indica que la función se evaluará en tiempo de compilación. 
   Lo que reduce el tiempo de ejecución de la función, ya que se resuelve durante la compilación, y no en tiempo de ejecución.
*/

int main() {
    constexpr const char* texto1 = "Este es un texto de prueba que tiene exactamente sesenta y cuatro.";
    constexpr const char* texto2 = "Este es un texto de prueba que tiene exactamente sesenta y cuatro.";

    // Medir tiempo de ejecución de compararRecursivo
    auto start1 = chrono::high_resolution_clock::now();
    bool result1 = compararRecursivo(texto1, texto2, 0);
    auto end1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1);

    // Medir tiempo de ejecución de compararEnTiempoDeCompilacion
    auto start2 = chrono::high_resolution_clock::now();
    constexpr bool result2 = compararEnTiempoDeCompilacion(texto1, texto2, 0);
    auto end2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2);

    // Mostrar resultados
    cout << "Los textos son iguales (compararRecursivo): " << (result1 ? "true" : "false") << endl;
    cout << "Tiempo de ejecución de compararRecursivo: " << elapsedTime1.count() << " nanosegundos" << endl;
    
    cout << "Los textos son iguales (compararEnTiempoDeCompilacion): " << (result2 ? "true" : "false") << endl;
    cout << "Tiempo de ejecución de compararEnTiempoDeCompilacion: " << elapsedTime2.count() << " nanosegundos" << endl;

    return 0;
}

// Función recursiva en tiempo de ejecución
bool compararRecursivo(const char* t1, const char* t2, int index) {
    if (t1[index] == '\0' && t2[index] == '\0') return true;
    if (t1[index] != t2[index]) return false;
    return compararRecursivo(t1, t2, index + 1);
}

// Función recursiva en tiempo de compilación
constexpr bool compararEnTiempoDeCompilacion(const char* t1, const char* t2, int index) {
    return (t1[index] == '\0' && t2[index] == '\0') ? true : 
           (t1[index] != t2[index]) ? false : 
           compararEnTiempoDeCompilacion(t1, t2, index + 1);
}


/*
Conclusión:
- La comparación en tiempo de ejecución toma un tiempo medible (en nanosegundos).
- La comparación en tiempo de compilación se resuelve durante la compilación, por lo que en tiempo de ejecución no tiene costo.
- Esto demuestra que la evaluación en tiempo de compilación puede optimizar significativamente el rendimiento del código eliminando operaciones innecesarias.
*/