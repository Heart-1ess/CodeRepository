#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateForMin(int &num1, int &num2){
        return num1 > num2 ? num2 : num1;
    }
    int calculateTimes(vector<int>& nums, string options){
        int times = 0;
        int init = 0;
        if (nums.size() <= 2) { return 0; }
        if (options == "odd"){ init = 0; }
        else if (options == "even"){ init = 1; }
        for (int i = init; i < nums.size(); i +=2){
            //left border: A[0] < A[1]
            if (i - 1 < 0){
                times += (nums[i] - nums[i + 1]) < 0 ? 0 : (nums[i] - nums[i + 1] + 1);
            }
            //right border: A[n-1]
            else if (i + 1 >= nums.size()){
                times += (nums[i] - nums[i - 1]) < 0 ? 0 : (nums[i] - nums[i - 1] + 1);
            }
            else{
                times += (nums[i] - calculateForMin(nums[i - 1], nums[i + 1])) < 0 ? 0 : (nums[i] - calculateForMin(nums[i - 1], nums[i + 1]) + 1);
            }
        }
        return times;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        //calculate odd => A[oddNum] < A[evenNum]
        odd = calculateTimes(nums, "odd");
        //calculate even => A[oddNum] > A[evenNum]
        even = calculateTimes(nums, "even");
        return calculateForMin(odd, even);
    }
};

int main(){
    vector<int> nums = {10,4,4,10,10,6,2,3};
    Solution sol = Solution();
    cout << sol.movesToMakeZigzag(nums) << endl;
    return 0;
}