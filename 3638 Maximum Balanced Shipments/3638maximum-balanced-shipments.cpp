class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int max=-1;
        int last=0;
        int l=0;
        int r=0;
        int c=0;
        while(r<n){
            if(weight[r]>max){
                max=weight[r];
            }
            last=weight[r];
            if(last<max){
                c++;
                max=-1;
                // while(a[l]<=last){
                //     l++;
                // }
                last=0;
            }
            r++;
        }
        return c;
    }
};