
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct processo {
    int pid;
    int ciclos;
    int reduzCiclos(int a) {
        if (ciclos>500){return ciclos = ciclos-a;}
        return ciclos=0;
    }
};

vector<int> round_robin(const vector<processo>& processos, int max_ciclos) {
    vector<int> concluidos;
    queue<processo> proc;
    int tam = processos.size();

    for (int i=0;i<tam;i++) {
        proc.push(processos[i]);
    }

    while (!proc.empty()) {
        proc.front().reduzCiclos(max_ciclos);
        if (proc.front().ciclos<=0) {
            concluidos.push_back(proc.front().pid);
            proc.pop();
            continue;
        }
        proc.push(proc.front());
        proc.pop();
    }

    return concluidos;
}

int main() {
    int max_ciclos = 500;

    std::vector<processo> processos = {
        {1, 1000},
        {2, 1500},
        {3, 2200},
        {4, 500},
        {5, 750},
        {6, 1250},
        {7, 120},
        {8, 5000}
    };

    auto concluidos = round_robin(processos, max_ciclos);

    cout << "Ordem de processos concluidos: " << endl;
    for (auto pid : concluidos) {
        cout << pid << " ";
    }
    cout << endl;

    return 0;
}