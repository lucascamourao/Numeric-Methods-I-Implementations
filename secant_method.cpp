#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float valor_func(float valor) {
    float y = - (exp(valor) / 2) + 2 * cos(valor);
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
    float epsilon, x, x_ante_anterior, x_anterior;
    bool check1, check2;
    int iterMax = 50;

    cout << "\nDigite o x0: ";
    cin >> x_ante_anterior;
    cout << "\nDigite o x1: ";
    cin >> x_anterior;
    cout << "\nDigite o epsilon: \n";
    cin >> epsilon;

    if (!checar_intervalo(x_ante_anterior, x_anterior)) {
        cout << "\nIntervalo invalido. Nao contem uma raiz.";
        return 1;
    }

    int i = 0;
    while (i <= iterMax) {
        float fx_ante_anterior = valor_func(x_ante_anterior);
        float fx_anterior = valor_func(x_anterior);

        if (abs(fx_ante_anterior) < epsilon) {
            x = x_ante_anterior;
            break;
        }

        if (abs(fx_anterior) < epsilon || abs(x_anterior - x_ante_anterior) < epsilon) {
            x = x_anterior;
            break;
        }

        x = ((x_ante_anterior * fx_anterior) - (x_anterior * fx_ante_anterior)) / (fx_anterior - fx_ante_anterior);

        check1 = abs(valor_func(x_ante_anterior)) < epsilon;
        check2 = abs(x - x_anterior) < epsilon;
        if (check1 || check2) {
            break;
        }

        x_ante_anterior = x_anterior;
        x_anterior = x;
        i++;
    }

    cout << "\nA raiz eh: " << x;

    return 0;
}
