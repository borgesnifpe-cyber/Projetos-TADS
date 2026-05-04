#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> s2;
        const int tam = s.size();
        int contador = 0;

        for (int i = 0; i < tam; i++) {
            if (tam==1 || s[0]=='}'||s[0]==')'||s[0]==']' || !(s2.empty()) && contador == tam) {
                return false;
            }

            if (s[i]=='(' || s[i]=='{' || s[i]=='[') {
                s2.push(s[i]);
                contador++;
                continue;
            }

            if (s2.empty() && (s[i]== ')' || s[i]== '}' || s[i]== ']')) {
                return false;
            }

            if (s[i]== ')' && s2.top() == '(') {
                s2.pop();
                contador++;
                continue;
            }

            if (s[i]== '}' && s2.top() == '{') {
                s2.pop();
                contador++;
                continue;
            }

            if (s[i]== ']' && s2.top() == '[') {
                s2.pop();
                contador++;
                continue;
            }
            return false;

        }
        if (contador==tam && s2.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    string testes[] = {
        "(", // I
        ")", // I
        "()", // V
        "[{()}]", // V
        "()[]{}", // V
        "{[(}])", // I
        "(][){}", // I
        "}{)(][" // I
    };

    for (auto &s : testes) {
        cout << s << ": ";
        cout << (Solution().isValid(s)?"Valida":"Invalida") << endl;
    };
}