int countSeniors(char ** details, int detailsSize){
    int s=0,age;
    for(int i=0;i<detailsSize;i++){
        age=(details[i][11]-'0')*10+(details[i][12]-'0');
        if(age>60){
            s++;
        }
    }
    return s;
}