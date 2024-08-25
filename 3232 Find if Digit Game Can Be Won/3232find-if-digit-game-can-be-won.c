bool canAliceWin(int* nums, int numsSize) {
    int s = 0, m = 0, left = 0;
    
    while (left <= numsSize - 1) {
        if (nums[left] >= 10) {
            m += nums[left];
        } else {
            s += nums[left];
        }
        left++;
    }
    int as=(s>m)?s:m;
    int bs=(s>m)?m:s;
    if(as>bs){
        return true;
    }
    return false;
}
