/* 
Numeric Methods I 2023.2 - Federal University of Ceará
Question 1 - Exercise 1
OBS: Use both ways to convert from binary do decimal
*/

#include <iostream>
#include <math.h>
#include <string> 
using namespace std; 

// inverts the string
string inverterString(const string& str) {
    int tamanho = str.length();
    string invertida = str;

    for (int i = 0; i < tamanho / 2; i++) {
        char temp = invertida[i];
        invertida[i] = invertida[tamanho - 1 - i];
        invertida[tamanho - 1 - i] = temp;
    }

    return invertida;
}

// Converts from decimal to binary
string dec_bin(int num_dec) {
    if (num_dec == 0) {
        return "0";
    }
    string bin = "";
    while (num_dec > 0) {
        bin += to_string(num_dec % 2);
        num_dec /= 2;
    }
    bin = inverterString(bin);
    
    return bin;
}

// Uma forma de fazer a conversão
// One of the ways to convert
int bin_dec1(int num_bin) {
    string bin = std::to_string(num_bin);
    int tamanho = bin.length();
    int aux = 0;
    int dec = 0;
    for (int i = tamanho - 1; i >= 0; i--) {   
        char digit = bin[i];
        int valor_binario = digit - '0'; // converts the binary character into numeric value
        dec += (valor_binario * pow(2, aux));
        aux++;
    }
    return dec;
}

// função aux recursiva para bin_dec2
// auxiliary function
int calc_Bj(int j, int aj) {
    // base case
    if (j == 0) {
        return aj;
    } else {
        int bj = 2 * calc_Bj(j - 1, aj);
        return bj;
    }
}

// Outra forma de fazer a conversão
// Another way to do the conversion
int bin_dec2(int num_bin) {
    string bin = std::to_string(num_bin);
    int tamanho = bin.length();

    int dec = 0;
    
    for (int i = 0; i < tamanho; i++) {
        int aj = bin[i] - '0';
        dec += calc_Bj(tamanho - i - 1, aj);
    }
    
    return dec;
}

int main() {
    cout << "BINARIO-DECIMAL: \n";
    cout << "Digite o numero em binario: \n";
    int bin;
    cin >> bin; 

    cout << "Metodo 1: \n";
    cout << bin_dec1(bin) << "\n";
    cout << "Metodo 2: \n";
    cout << bin_dec2(bin) << "\n";


    cout << "DECIMAL-BINARIO: \n";
    cout << "Digite o numero em decimal: \n";
    int dec; 
    cin >> dec;
    cout << "Metodo: \n";
    cout << dec_bin(dec) << "\n";

    return 0;
}