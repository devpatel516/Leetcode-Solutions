bool rotateString(char* s, char* goal) {
    char temp;
    int len = strlen(s);
    if (len != strlen(goal)) {
        return false;
    }
    for(int i=0;i<len;i++){
        if(strcmp(s,goal)==0){
            return true;
        }
        temp=s[0];
        for(int j=0;j<len-1;j++){
            s[j]=s[j+1];
        }
        s[len-1]=temp;
    }
    return false;
}