#include <iostream>
#include <vector>

using namespace std;
// Para cada valor de n o array precisará trocar o lugar dos valores no vetor para a direita
// caso o valor seja positivo e para a esquerda caso o valor seja negativo
// Eu vou percorrer todos os valores do vetor para trocá-los de lugar portanto o loop será em função
// do tamanho do vetor

void rotate(vector<int> &arr, int n) {
    vector<int> f={};
    f.resize(arr.size());
    const unsigned long tamanho=arr.size();

    if (n==0) {
        f = arr;
    }

    for (int i=0; i<tamanho; i++) {
        f.at(i)=arr.at((((i-n)%tamanho) + tamanho)%tamanho); //0 =
    }
    arr.swap(f);
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr2 = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr3 = {3, 5, 8, 10, 1, 7, 9, 4};
    vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr5 = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr6 = {3, 5, 8, 10, 1, 7, 9, 4};

    rotate(arr1, 2);
    for (auto & v : arr1) cout << v << " "; // 7 8 1 2 3 4 5 6
    cout << endl;

    rotate(arr2, 5);
    for (auto & v : arr2) cout << v << " "; // 5 4 3 2 1 8 7 6
    cout << endl;

    rotate(arr3, 3);
    for (auto & v : arr3) cout << v << " "; // 7 9 4 3 5 8 10 1
    cout << endl;

    rotate(arr4, -2);
    for (auto & v : arr4) cout << v << " "; // 3 4 5 6 7 8 1 2
    cout << endl;

    rotate(arr5, -5);
    for (auto & v : arr5) cout << v << " "; // 3 2 1 8 7 6 5 4
    cout << endl;

    rotate(arr6, -3);
    for (auto & v : arr6) cout << v << " "; // 10 1 7 9 4 3 5 8
    cout << endl;

    return 0;
}