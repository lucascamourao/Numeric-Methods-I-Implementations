#include <iostream>
#include <math.h>
#include <string> 
using namespace std; 

// Calcula o valor de f(x), sendo f uma função definida dentro de valor_func
float valor_func(float valor) {
    float y = valor - (valor * log(valor)); 
    return y;
}

float phi(float valor) {
    float y = valor/ (log(valor));
    return y;
}

int main() {
    float x, x_anterior;
    float epsilon = 0.00001;
    int iterMax = 50; // maximo de iteraçoes

    cout << "\nDigite o x0: \n";
    cin >> x_anterior; 
    // Dica: use x0 = 2;

    int i = 0;
    while (i <= iterMax) {
        x = phi(x_anterior);
        if ((valor_func(x) < epsilon) && (abs(x - x_anterior) < epsilon)) {
            break;
        }
        x_anterior = x;
        i++;
    }

    cout << "\nA raiz eh: " << x;

    return 0; 
}