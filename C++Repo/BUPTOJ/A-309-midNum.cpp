#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    float midNum(vector<int>& array){
        if (array.size() % 2 == 0){
            return ((array[array.size() / 2] + array[array.size() / 2 - 1]) / 2.0);
        }
        else return array[array.size() / 2];
    }
};

int main(){
    int count, num, temp;
    vector<int> array, result;
    Solution sol = Solution();
    cin >> count;
    for (int j = 0; j < count; j ++){
        cin >> num;
        array.clear();
        for (int k = 0; k < num; k ++){
            cin >> temp;
            array.push_back(temp);
        }
        cout << sol.midNum(array) << endl;
    }
    return 0;
}