

char * defangIPaddr(char * address){
    int length=strlen(address),j=0;
    char *new=(char *)malloc(length+7+1);
    for(int k=0;k<length;k++){
    if(address[k]=='.'){
        new[j++]='[';
        new[j++]='.';
        new[j++]=']';
    }
    else{
        new[j++]=address[k];
    }
    }
    new[j]='\0';
    return new;
}