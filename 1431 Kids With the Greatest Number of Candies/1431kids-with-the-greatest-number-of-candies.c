/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize=candiesSize;
    bool *result=(bool *)malloc(*returnSize*sizeof(bool));
    int m=0;
    for(int i=0;i<candiesSize;i++){
        if(m<candies[i]){
            m=candies[i];
        }
    }
    for(int i=0;i<candiesSize;i++){
        candies[i]=candies[i]+extraCandies;
        if(candies[i]>=m){
            result[i]=true;
        }
        else{
            result[i]=false;
        }
    }
    return result;
}