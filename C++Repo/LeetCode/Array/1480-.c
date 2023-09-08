#include <stdio.h>
#include <malloc.h>

int* runningSum(int* nums, int numsSize, int* returnSize){
    int temp;
    temp = 0;
    returnSize = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        temp += nums[i];
        returnSize[i] = temp;
    }
    return returnSize;
}

int main(){
    int nums[4] = {1,2,3,4};
    int* returnSize;
    printf(runningSum(nums, 4, returnSize));
    free(returnSize);
    return 0;
}
