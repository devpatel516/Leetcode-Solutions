class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total<x){
            return -1;
        }
        else if(total==x){
            return nums.size();
        }
        int k=total-x;
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int temp=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            if(sum==k){
                temp=max(temp,(r-l)+1);
            }
            r++;
        }
        cout<<temp<<endl;
        if(temp==0){
            return -1;
        }
        return n-temp;
    }
};