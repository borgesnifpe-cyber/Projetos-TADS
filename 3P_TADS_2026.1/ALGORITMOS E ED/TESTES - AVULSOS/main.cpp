#include <iostream>
using namespace std;

class Retangulo {
private:
    int largura;
    int altura;

public:
    Retangulo(int l, int a) {
        largura = l;
        altura = a;
    }

    int area() {
        return largura * altura;
    }

    void setAltura(int a) {
        altura = a;
    }
};

int main() {
    Retangulo r1(4, 5);
    cout << r1.area() << endl;

    r1.setAltura(10);
    cout << r1.area() << endl;

    return 0;
}
