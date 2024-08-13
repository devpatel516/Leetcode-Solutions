int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int m=0,p=0,i;
    for(i=0;i<numsSize;i++){
        if(nums[i]==1){
            p++;
        }
        else{
            p=0;
        }
        if(p>m){
            m=p;
        }
    }
    return m;
}