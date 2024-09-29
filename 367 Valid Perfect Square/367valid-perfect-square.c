bool isPerfectSquare(int num) {
    if(num<0) return false;
    long long l=1,m;
    long long r=num;
    while(l<=r){
        m=(l+r)/2;
        if(m*m == num){
            return true;
        }
        else if (m*m < num){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return false;
}