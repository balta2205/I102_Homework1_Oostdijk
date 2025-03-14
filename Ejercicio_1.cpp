#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int n;
    cout << "Ingrese un numero entero, positivo y mayor a 1 para formar la matriz cuadrada: ";
    cin >> n;

    if(n <= 1){
        cout << "El numero ingresado no es valido." << endl;
        return 0;
    }

    int matriz[n][n];
    int m = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = m;
            m++;
        }
    }

    int* puntero = &matriz[0][0] + (n*n - 1);
    int contador = n*n - 1;

    for(; puntero >= &matriz[0][0]; puntero--){
        cout << "Matriz[" << contador/n << "][" << contador%n << "] = " << *puntero << endl;
        contador--;
    }
    
    return 0;
}