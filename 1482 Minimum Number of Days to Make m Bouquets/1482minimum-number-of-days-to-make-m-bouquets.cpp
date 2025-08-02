class Solution {
public:
    int possible(vector<int>& bloomDay,int day,int m,int k){
        int c=0;
        int nb=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                c++;
            }
            else{
                nb+=c/k;
                c=0;
            }
        }
        nb+=c/k;
        if(nb>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(bloomDay.size()<m*k){
        //     return -1;
        // }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
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