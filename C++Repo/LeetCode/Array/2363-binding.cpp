#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void itemSwap(vector<int>& item1, vector<int>& item2){
        vector<int> temp;
        temp = item1;
        item1 = item2;
        item2 = temp;
    }
    void itemSortByValue(vector<vector<int>>& item){
        for (int i = 0; i < item.size(); i ++){
            for (int j = 0; j < item.size() - i - 1; j ++){
                if (item[j][0] > item[j + 1][0]){
                    itemSwap(item[j], item[j + 1]);
                }
            }
        }
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ret;
        itemSortByValue(items1);
        itemSortByValue(items2);
        vector<vector<int>>::iterator it1 = items1.begin();
        vector<vector<int>>::iterator it2 = items2.begin();
        while(it1 != items1.end() || it2 != items2.end()){
            if (it2 == items2.end()){
                ret.push_back(*it1);
                it1 ++;
            }
            else if (it1 == items1.end()){
                ret.push_back(*it2);
                it2 ++;
            }
            else if ((*it1)[0] == (*it2)[0]){
                vector<int> temp;
                temp.push_back((*it1)[0]);
                temp.push_back((*it1)[1] + (*it2)[1]);
                ret.push_back(temp);
                it1 ++;
                it2 ++;
            }
            else if ((*it1)[0] < (*it2)[0]){
                ret.push_back(*it1);
                it1 ++;
            }
            else if ((*it1)[0] > (*it2)[0]){
                ret.push_back(*it2);
                it2 ++;
            }
        }
        return ret;
    }
};

int main(){
    vector<vector<int>> items1 = {{1,1},{4,5},{3,8}};
    vector<vector<int>> items2 = {{3,1},{1,5}};
    vector<vector<int>> res;
    Solution sol = Solution();
    res = sol.mergeSimilarItems(items1, items2);
    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}