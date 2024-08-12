/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int c;
    int *ans=(int *)malloc(*returnSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        c=0;
        for(int j=0;j<numsSize;j++){
            if(nums[i]>nums[j]){
                c++;
            }
        }
        ans[i]=c;
    }
    return ans;
}