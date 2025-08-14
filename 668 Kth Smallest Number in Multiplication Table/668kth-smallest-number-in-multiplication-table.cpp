class Solution {
public:
    int func(int m,int n,int x){
        int count=0;
        for(int i=1;i<=m;i++){
            count+=min(n,x/i);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1;
        int h=m*n;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(func(m,n,mid)<k){
                l=mid+1;
            }
            else{
                ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
};