/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    *returnSize=wordsSize;
    int b=0;
    int *ans=(int *)malloc(*returnSize*sizeof(int));
    for(int i=0;i<wordsSize;i++){
        int a=strlen(words[i]);
        for(int j=0;j<a;j++){
            if(words[i][j]==x){
                ans[b]=i;
                b++;
                break;
            }
        }
    }
    *returnSize=b; 
    return ans;    
}