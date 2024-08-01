bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m=matrixSize,mid;
    int n=*matrixColSize;
    int left=0;
    int right=(m*n)-1;
    while(left<=right){
        mid=(left+right)/2;
        if(matrix[mid/n][mid%n]==target){
            return true;
        }
        else if(matrix[mid/n][mid%n]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return false;
}