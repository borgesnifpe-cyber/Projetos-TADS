#include <iostream>
#include <vector>

using namespace std;

class fila_media {
private:
    vector<int> itens;
    // sugestao de atributos; pode/deve haver outros
    int ini = 0,   // posicao do 1o elemento
        fin = 0,  // posicao do último elemento na lista
        tam = 0,   // tamanho (numero atual de elementos)
        cap = 0,    // capacidade (numero max. de elementos)
        total = 0;

public:
    // construtor receba capacidade; inicializa cap e o vector itens.
    explicit fila_media(int cap) : itens(cap), cap(cap) {  }

    // fila esta cheia?
    bool cheia() const {
        if (tam == cap) {return true;}
        return false;
    }

    // fila esta vazia?
    bool vazia() const {
        if (tam == 0) {return true;}
        return false;
    }

    // remove elemento na frente da fila
    void desenfileira() {
        if (vazia()) {
            throw runtime_error("Fila vazia");
        }
        if (tam > 0) {
            total -= itens[ini];
            tam--;
            ini = (ini+1)%cap;
        }
    }

    // adiciona i ao final da fila
    void enfileira(int i) {
        if (cheia()) {
            throw runtime_error("Fila cheia");
        }
        if (tam < cap) {
            itens[fin] = i;
            total +=i;
            fin = (fin+1)%cap;
            tam++;
        };
    }

    // retorna elemento na frente da fila
    int proximo() {
        return itens[ini];
    }

    // retorna atual media dos elementos
    double media() const {
        double med= static_cast<double>(total)/static_cast<double>(tam);
        return med;
    }

    // retorna o numero de elementos na fila
    int tamanho() {
        return tam;
    }
};

int main() {
    vector<int> arr = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};

    fila_media fila(4);

    for (int i : arr) {
        if (fila.cheia()) fila.desenfileira();

        fila.enfileira(i);

        cout << fila.media() << " ";
    }

    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7
    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7
    return 0;
}
