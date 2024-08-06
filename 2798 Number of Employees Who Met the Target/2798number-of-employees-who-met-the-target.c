int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target){
    int m=0;
    for(int i=0;i<hoursSize;i++){
        if(target<=hours[i]){
            m++;
        }
    }
    return m;
}