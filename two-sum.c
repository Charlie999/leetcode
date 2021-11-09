#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;

    for (int i=0;i<numsSize;i++) {
        for (int j=i+1;j<numsSize;j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    *returnSize = 0; // shouldn't happen
    return ret;
}

int main() {
 int nums[5] = {1,2,3,4,5};
 int numsSize = 5;
 int target = 9;
 int returnSize = 0;

 int* ret = twoSum(nums, numsSize, target, &returnSize);

 printf("[%d,%d]\n",ret[0],ret[1]);

 return 0;
}
