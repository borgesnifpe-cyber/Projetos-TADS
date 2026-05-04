#include <iostream>
#include <vector>

using namespace std;

int maior(const vector<int> &arr, int n) {
    vector<int>meuArray(arr.begin(),arr.end());

    if (n<1) {
        cout<<"Não há valores a comparar";
        return -99;
    }

    if (n==1) {
        return meuArray[0];
    }

    if (meuArray.at(n-1)>meuArray.at(n-2)) {
        meuArray[n-2]=meuArray[n-1];
    }
    meuArray.pop_back();

    return maior(meuArray,meuArray.size());
}

int main() {
    vector<int> arr1 = {1, 1, 1, 1, 1, 1, 1, 2};
    vector<int> arr2 = {-1, -2, -3, -4, -5, -6};
    vector<int> arr3 = {10, 1, 5, 3, 12, 7, 4, 6};

    cout << maior(arr1, arr1.size()) << endl; // 2
    cout << maior(arr2, arr2.size()) << endl; // -1
    cout << maior(arr3, arr3.size()) << endl; // 12
    return 0;
}
