class Solution {
public:
    int minOperations(vector<int>& nums) {
        //if freq==1 than -1
        //if even than freq/2
        //if odd and multiple of 3 than freq/3
        //if odd and not multiple of 3 than (freq-1)/2+1

        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }    
        int ans=0;
        for(auto k:mp){
            //cout<<k.first<<" "<<k.second<<endl;
            if(k.second==1){
                return -1;
            }
            if(k.second%3==0){
                ans+=k.second/3;
            }
            else if(k.second%3!=0){
                int x=(k.second-1)/3+1;
                int y=k.second/2;
                //cout<<x<<" "<<y<<endl;
                ans+=min(x,y);
            }
        }
        return ans;
    }
};