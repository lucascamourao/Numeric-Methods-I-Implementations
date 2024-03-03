// Método do Polinômio

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float valor_func(float valor) {
    float y = pow(valor, 3) - 9 * valor + 3;
    return y;
}

float dx(float valor) {
    float y = 3 * pow(valor, 2) - 9;
    return y;
}

int main() {
    float epsilon, x, b, c, deltax;
    int iterMax = 50; 
    int i = 0;

    cout << "\nDigite o x0: ";
    cin >> x;
    cout << "\nDigite o epsilon: \n";
    cin >> epsilon;

    deltax = x;

    while (i <= iterMax) {
        b = valor_func(x);  
        c = dx(x);
        if ((abs(b) < epsilon) || abs(deltax) < epsilon) {
            break;
        }
        deltax = b/c;
        x = x - deltax;
        i++;
    }

    cout << "\nA raiz eh: " << x;

    return 0;
}
