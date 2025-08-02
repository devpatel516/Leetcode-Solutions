class Solution {
public:
    bool cap(vector<int>& weights,int capacity,int days){
        int sum=0;
        int temp=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=capacity){
                sum+=weights[i];
            }
            else{
                sum=weights[i];
                temp++;
            }
        }
        if(temp<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans;
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(cap(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};