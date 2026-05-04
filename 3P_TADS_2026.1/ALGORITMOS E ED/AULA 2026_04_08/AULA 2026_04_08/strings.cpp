#include <iostream>
#include <vector>

using namespace std;

string reordenar(const string &str) {
   vector<char> s (str.begin(),str.end());
    string ordem ={};
    char letra;
    if (s.empty()) {
        return "Não há input";
    }
    for (int i=s.size()-1;i>=0;i--) {
        letra=s.at(i);
        s.pop_back();
        if (ordem.empty()) {
            ordem.insert(ordem.begin(),letra);
            continue;
        }
        if (letra>ordem.at(ordem.size()-1)){
            ordem.push_back(letra);
        } else {
            int posMenor = -1;
            for (int j=ordem.size()-1;j>=0;j--) {
                if (letra<=ordem.at(j)) {
                    posMenor=j;
                }
            }
            if (posMenor==-1) {
                ordem.insert(ordem.begin(),letra);
            } else {
                ordem.insert(ordem.begin()+posMenor,letra);
            }
        }
    }
    return ordem;
}

int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("banana")) << endl;
    cout << reordenar(string("nathan")) <<endl;
};