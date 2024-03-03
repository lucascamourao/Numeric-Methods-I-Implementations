#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Método de Newton-Raphson/ Polinômio

float valor_func(float valor) {
    float y = - (exp(valor) / 2) + 2 * cos(valor);
    return y;
}

float dx(float valor) {
    float y = (-0.5 * exp(valor)) - 2 * sin(valor);
    return y;
}

bool checar_intervalo(float a0, float b0) {
    float valor_a0 = valor_func(a0);
    float valor_b0 = valor_func(b0);

    if ((valor_a0 * valor_b0) < 0) {
        return true;
    }
    return false;
}

int main() {
    float epsilon, x, x_anterior;
    int iterMax = 50;

    cout << "\nDigite o x0: ";
    cin >> x_anterior;
    cout << "\nDigite o epsilon: \n";
    cin >> epsilon;

    int i = 0;
    bool check2, check3;

    while (true) {
        if (i > iterMax) {
            cout << "\nNao foram achadas raizes. ";
            break;
        }

        float fx_anterior = valor_func(x_anterior);
        if (abs(fx_anterior) < epsilon) {
            x = x_anterior;
            break;
        }

        float fx_anterior_dx = dx(x_anterior);
        x = x_anterior - (fx_anterior / fx_anterior_dx);
        
        check2 = abs(valor_func(x)) < epsilon;
        check3 = abs(x - x_anterior) < epsilon;
        if (check2 || check3) {
            break;
        }
        x_anterior = x;
        i++;
    }

    cout << "\nA raiz eh: " << x;

    return 0;
}
