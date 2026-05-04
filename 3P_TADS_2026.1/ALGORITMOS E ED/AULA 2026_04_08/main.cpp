#include <iostream>
using namespace std;

int fib(int x) {
    if (x==1 || x==0) {
        return x;
    }
    return fib(x-1) + fib(x-2);
}

int main() {
    int numero=0;

    cout << "Calcule o Fibonacci do numero:";
    cin >> numero;
    cout << "O numero " << numero << " de Fibonnaci e: " << fib(numero);

    return 0;
}