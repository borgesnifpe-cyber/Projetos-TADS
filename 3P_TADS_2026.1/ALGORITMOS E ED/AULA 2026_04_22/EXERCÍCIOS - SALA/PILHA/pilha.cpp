#include <stdexcept>
#include "pilha.h"

using namespace std;

Pilha :: Pilha(int cap) : num_itens(0), itens(cap) {
}

Pilha :: ~Pilha() {}


void Pilha::empilhar(int v) {
    if (num_itens >= itens.size()) {
        throw runtime_error("Stack Overflow");
    }
    itens[num_itens++] = v;
    num_itens++;
}

void desempilhar() {
    if (num_itens == 0) {
        throw runtime_error("Stack Underflow");
    }
    if (num_itens > 0) num_itens--;
}

int topo() {
    if (num_itens >= itens.size()) {
        throw runtime_error("Stack Overflow");
    }
    return itens[num_itens-1];
}

int altura() {
    return num_itens;
};