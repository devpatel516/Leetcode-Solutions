class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> unsign;
        for(auto x:nums){
            unsign.push_back(1LL*abs(x)*abs(x));
        }

        sort(unsign.begin(),unsign.end());
        long long half=n/2;
        long long sub=0;
        //cout<<half<<endl;
        for(long long i=0;i<half;i++){
            sub+=unsign[i];
        }

        long long add=0;
        for(long long i=half;i<n;i++){
            add+=unsign[i];
        }

        return add-sub;
    }
};