#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int> count;
        vector<bool> iftrust;
        for (int k = 0; k < n+1; k ++){
            count.push_back(0);
            iftrust.push_back(false);
        }
        int result = -1;
        int num = 0;
        for (int i = 0; i < trust.size(); i ++){
            count[trust[i][1]] ++;
            iftrust[trust[i][0]] = true;
        }
        for (int j = 1; j <= n; j ++){
            if (count[j] == n - 1 && iftrust[j] == false){
                result = j;
                num ++;
            }
        }
        if (num == 1){
            return result;
        }
        else {
            return -1;
        }
    }
};

int main(){
    vector<vector<int>> trust = {{1, 2}};
    int n = 2;
    Solution sol = Solution();
    cout << sol.findJudge(n, trust);
    return 0;
}