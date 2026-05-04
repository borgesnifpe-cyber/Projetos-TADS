#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        int res = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]==0) {
                    continue;
                }
                if (grid[i][j] == 1) {
                    int contador = 0;
                    for (int k = i-1; k <= i+1; k++) {
                        if (k<0 || k>=M) {continue;};
                        for (int l = j-1; l <= j+1; l++) {
                            if (l<0 || l>=N) {continue;};
                            if (k==i-1 && l==j-1||k==i+1 && l==j+1 || k==i+1 && l==j-1 || k==i-1 && l==j+1||k==i && l==j) {continue;};
                            if (grid[k][l]==1) {
                                contador++;
                            } ;
                        }
                    } res = res + (4-contador);
                }
            }
        } return res;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << Solution().islandPerimeter(grid) << endl; // res = 16

    return 0;
}
