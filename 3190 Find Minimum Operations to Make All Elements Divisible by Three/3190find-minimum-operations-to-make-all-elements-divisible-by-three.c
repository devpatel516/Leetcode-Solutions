int minimumOperations(int* nums, int numsSize) {
    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        int a = nums[i] % 3;
        while (a != 0) {
            if (a == 1 || a == 2) {
                c++;
                break;
            }
        }
    }
    return c;
}