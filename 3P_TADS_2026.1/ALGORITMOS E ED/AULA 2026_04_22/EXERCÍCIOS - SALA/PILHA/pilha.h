#ifndef EXERCICIOS_PILHA_H
#define EXERCICIOS_PILHA_H

#include <vector>

using namespace std;

class Pilha {
private:
    int num_itens;
    vector <int> itens;

public:
    Pilha(int cap) : num_itens(0), itens(cap){};

    ~Pilha();

    void empilhar(int v);

    void desempilhar();

    int topo() const;

    int altura() const;
};

#endif //EXERCICIOS_PILHA_H
