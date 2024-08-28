char* reversePrefix(char* word, char ch) {
    int left,right,m=0,temp;
    for(int i=0;word[i]!='\0';i++){
    if(ch==word[i]){
        m=i;
        break;
    }
    }
    left=0;
    right=m;
    while(left<right){
        temp=word[left];
        word[left]=word[right];
        word[right]=temp;
        left++;
        right--;
    }
    return word;
}