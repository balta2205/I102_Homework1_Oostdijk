#include "Ejercicio_1.h"

using namespace std;

/* Se le pide al usuario un número entero positivo mayor a 1, con el cual se crea una matriz cuadrada de tamaño NxN.  
   Luego, se llena la matriz con valores en orden creciente.  

   A continuación, se define un puntero que apunta a la última posición del arreglo subyacente en memoria.  
   Utilizando un único ciclo `for`, se recorre el arreglo en orden inverso (de la última posición a la primera),  
   imprimiendo los valores junto con sus respectivos índices.  

   Esto es posible porque, al utilizar un arreglo unidimensional para almacenar los elementos de la matriz,  
   estos ocupan un bloque contiguo de memoria, permitiendo recorrerlos mediante aritmética de punteros,  
   decrementando el puntero en cada iteración. 
*/

int main(){

    // Se le pide al usuario un número entero positivo mayor a 1.
    int n;
    cout << "Ingrese un numero entero, positivo y mayor a 1 para formar la matriz cuadrada: ";
    cin >> n;

    if(n <= 1){
        cout << "El numero ingresado no es valido." << endl;
        return 0;
    }

    // Se crea una matriz cuadrada de tamaño NxN y se llena con valores en orden creciente.
    int matriz[n][n];
    int m = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = m;
            m++;
        }
    }

    // Llamada a la función para imprimir la matriz en orden inverso
    imprimirMatrizInversa(&matriz[0][0], n);
    
    return 0;
}

void imprimirMatrizInversa(int* matriz, int n) {
    int* puntero = matriz + (n * n - 1); // Apunta al último elemento de la matriz
    int contador = n * n - 1;

    for (; puntero >= matriz; puntero--) {
        cout << "Matriz[" << contador / n << "][" << contador % n << "] = " << *puntero << endl;
        contador--;
    }
}
