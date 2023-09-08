#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        vector<int>::iterator prev = height.begin();
        vector<int>::iterator rear = height.end() - 1;
        int area = 0;
        while(prev != rear){
            area = max(area, (int)((rear - prev) * min((*prev), (*rear))));
            if ((*prev) < (*rear)){
                prev ++;
            }
            else {
                rear --;
            }
        }
        return area;
    }
};

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol = Solution();
    cout << sol.maxArea(height) << endl;
    return 0;
}