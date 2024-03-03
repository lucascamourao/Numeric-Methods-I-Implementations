#include <iostream>
#include <math.h>
#include <string> 
using namespace std; 

// Calcula o valor de f(x), sendo f uma função definida dentro de valor_func
float valor_func(float valor) {
    float y = - (exp(valor) / 2) + 2 * cos(valor); 
    return y;
}

// Checa se no intervalo tem raizes, ou seja, se tem uma troca de sinal (ponto de inflexão)
bool checar_intervalo(float a0, float b0){
    float valor_a0 = valor_func(a0);
    float valor_b0 = valor_func(b0); 

    if ((valor_a0 * valor_b0) < 0) {
        return true;
    }
    return false; // funçao nao tem raizes nesse intervalo
}

int main() {
    float a, b;
    bool check1 = false;
    float epsilon;

    while (check1 != true) {
        cout << "Digite o intervalo: \n";
        cout << "a0: \n";
        cin >> a;
        cout << "b0: \n";
        cin >> b;

        check1 = checar_intervalo(a, b);
    }

    cout << "\nDigite o epsilon: \n";
    cin >> epsilon; 

    bool check2 = abs(b - a) > epsilon; 
    int iterMax = 50; // maximo de iteraçoes
    int i = 0;
    float x;
    while (check2 == true && i <= iterMax) {
        double fa = valor_func(a); // f(a)
        double fb = valor_func(b); // f(b)
        x = ((a*fb) - (b*fa))/ (fb - fa); // xi 
        double fx = valor_func(x); // f(xi)

        if (fa * fx > 0) {
            a = x; 
            fa = fx;
        }
        else {
            b = x;
            fb = fx;
        }
        i++;
    }

    cout << "\nA raiz eh: " << x;

    return 0; 
}