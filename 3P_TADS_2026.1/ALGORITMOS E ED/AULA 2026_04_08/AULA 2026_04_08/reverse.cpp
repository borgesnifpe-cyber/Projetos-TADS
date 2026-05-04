#include <iostream>
#include <vector>

using namespace std;

string inverter(const string &s) {
    string r(s.begin(),s.end());
    char temp;
    if (s.empty()) {
        return "String inválida para inversão";
    }
    if (r.size()<=1) {
        return r;
    }
    temp = r.at(r.size()-1);
    r.pop_back();
    return temp + inverter(r);
};

int main() {
    cout << inverter("recursao") << endl;  // oasrucer
    cout << inverter("banana") << endl;    // ananab
    cout << inverter("ifpe") << endl;      // epfi
    cout << inverter("micro-ondas") << endl; // sadno-orcim
    cout << inverter("nathan") << endl; // nahtan
}