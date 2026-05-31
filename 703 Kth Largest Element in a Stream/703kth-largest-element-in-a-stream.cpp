class KthLargest {
public:
    map<int,int> mp;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums){
            mp[x]++;
        }
        K=k;
    }
    
    int add(int val) {
        mp[val]++;
        int remaining=K;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            remaining-=it->second;
            if(remaining<=0){
                return it->first;
            }
        }    
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */