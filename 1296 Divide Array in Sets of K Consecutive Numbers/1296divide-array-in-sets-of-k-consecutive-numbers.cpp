class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        

        while(!mp.empty()){
            auto x=mp.begin();
            int start = x->first;
            for(int i=start;i<start+k;i++){
                if(!mp.count(i)){
                    return false;
                }
                mp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};