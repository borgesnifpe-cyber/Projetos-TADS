#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Pilha {
    private:
        int num_itens;
        vector <int> itens;

    public:
    Pilha(int cap) : num_itens(0), itens(cap) {
       // num_itens = 0;
    }

    ~Pilha() {}

    void empilhar(int v) {
        if (num_itens >= itens.size()) {
            throw runtime_error("Stack Overflow");
        }
        itens[num_itens+1] = v;
        num_itens++;
    }

    void desempilhar() {
        if (num_itens == 0) {
            throw runtime_error("Stack Underflow");
        }
        if (num_itens > 0) num_itens--;
    }

    int topo() const {
        if (num_itens >= itens.size()) {
            throw runtime_error("Stack Overflow");
        }
        return itens[num_itens-1];
    }

    int altura() const {
        return num_itens;
    }
};

int main() {

    Pilha pilha(10);

    try {
        pilha.empilhar(10);
        pilha.empilhar(25);
        pilha.empilhar(30);

        cout << pilha.topo() << endl;
        cout << pilha.altura() << endl;

        for (int i = 0; i < pilha.altura(); i++) {
        }
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}