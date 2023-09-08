#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int jump(vector<int>& nums){
        int pos = 0;
        int count = 0;
        if (nums.size() == 1){
            return 0;
        }
        while (true){
            if (pos + nums[pos] >= nums.size() - 1){
                count ++;
                break;
            }
            else {
                int temp = pos;
                for (int i = pos + 1; i <= pos + nums[pos]; i ++){
                    temp = i + nums[i] > temp + nums[temp] ? i : temp;
                }
                pos = temp;
                count ++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> nums = {2,1,1,1,1};
    Solution sol = Solution();
    cout << sol.jump(nums) << endl;
    return 0;
}