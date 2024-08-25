bool judgeSquareSum(int c) {
    long left,right,sum;
    if(c==0){
            return true;
        }
    left=0;
    right=sqrt(c);
    while(left<=right){
        sum=(left*left)+(right*right);
        if(sum==c){
            return c;
        }
        else if(sum<c){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}