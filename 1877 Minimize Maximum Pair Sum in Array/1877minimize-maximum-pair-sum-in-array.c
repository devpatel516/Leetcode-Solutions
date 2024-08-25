int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    int left,right,s,m=0;
    left=0;
    right=numsSize-1;
    while(left<=right){
        s=nums[left]+nums[right];
        if(m<s){
            m=s;
        }
        left++;
        right--;
    }
    return m;
}