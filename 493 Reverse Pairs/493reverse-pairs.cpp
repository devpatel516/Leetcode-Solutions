class Solution {
public:
    int ans=0;
    void count(int low,int mid,int high,vector<int> &nums){
        int r=mid+1;

        for(int i=low;i<=mid;i++){
            while(r<=high && nums[i]>(long long)2*nums[r]){
                r++;
            }
            ans+=(r-(mid+1));
        }
    };
    void merge(int low,int mid,int high,vector<int> &a){
        vector<int> temp;
        int l=low;
        int r=mid+1;
        while(l<=mid && r<=high){
            if(a[l]<a[r]){
                temp.push_back(a[l]);
                l++;
            }
            else{
                temp.push_back(a[r]);
                r++;
            }
        }

        while(l<=mid){
            temp.push_back(a[l]);
            l++;
        }

        while(r<=high){
            temp.push_back(a[r]);
            r++;
        }

        for(int i=low;i<=high;i++){
            a[i]=temp[i-low];
        }
    }
    void mergesort(int low,int high,vector<int> &nums){
        if(low>=high){
            return ;
        }
        int mid=(low+high)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        count(low,mid,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return ans;
    }
};