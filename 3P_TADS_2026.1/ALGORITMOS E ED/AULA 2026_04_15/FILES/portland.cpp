#include <iostream>
#include <vector>

using namespace std;

void portland(const vector<vector<int>> &M) {
    const int N = M.size();
    const int M1 = M[0].size();
    vector<vector<string>> result(N, vector<string>(M1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M1; j++) {
            if (i+1>=M1||j+1>=N) continue;

            if (M[i][j]==0) {
                if (M[i][j+1]==0||M[i+1][j]==0||M[i+1][j+1]==0) {
                    result[i][j] = "U";
                }
                if (M[i][j+1]==1 && M[i+1][j]==1 || M[i][j+1]==1 && M[i+1][j+1]==1 || M[i+1][j]==1 && M[i+1][j+1]==1) {
                    result[i][j] = "S";
                }
            }

            if (M[i][j]==1){
                if (M[i][j+1]==1||M[i+1][j]==1||M[i+1][j+1]==1){
                    result[i][j] = "S";
                } else {
                    result[i][j] = "U";
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M1; j++) {
            if (result[i][j] == "") continue;
            cout << result[i][j];
        }
        cout << endl;
    }
};

int main() {
    // vector<vector<int>> M(n, vector<int>(n));
    const vector<vector<int>> M1 = {{1, 0},
                                    {0, 0}};
    const vector<vector<int>> M2 = {{1, 0, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    const vector<vector<int>> M3 = {{1, 1, 0, 1},
                                    {1, 0, 1, 0},
                                    {1, 0, 0, 1},
                                    {0, 1, 1, 0}};

    cout << "Caso 1:" << endl;
    portland(M1);
    cout << "Caso 2:" << endl;
    portland(M2);
    cout << "Caso 3:" << endl;
    portland(M3);
    return 0;
}