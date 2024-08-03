int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int *wealth=(int *)malloc(accountsSize*sizeof(int));
    int i,j;
    for(i=0;i<accountsSize;i++){
        wealth[i]=0;
        for(j=0;j<accountsColSize[i];j++){
            wealth[i]=wealth[i]+accounts[i][j];
        }
    }
    int m=0;
    for(i=0;i<accountsSize;i++){
    if(wealth[i]>m){
        m=wealth[i];
    }
    }
    return m;
}