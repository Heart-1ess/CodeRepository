#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxValue(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; i ++){
            for (int j = 0; j < n; j ++){
                if (i > 0){
                    f[i][j] = max(f[i][j], f[i - 1][j]);
                }
                if (j > 0){
                    f[i][j] = max(f[i][j], f[i][j - 1]);
                }
                f[i][j] += grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};

int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sol = Solution();
    cout << sol.maxValue(grid) << endl;
    return 0;
}