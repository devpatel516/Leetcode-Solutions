int maxPower(char* s) {
    int i,p=1,m=1;
    for(int i=1;i<strlen(s);i++)
    {   
        if(s[i]==s[i-1]){
            p++;
        }
        else{
            p=1;
        }
        if(p>m)
        {
                m=p;
        }
    }
    return m;
}