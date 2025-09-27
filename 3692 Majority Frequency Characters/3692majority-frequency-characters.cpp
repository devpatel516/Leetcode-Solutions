class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        vector<int> f(101,0);
        for(auto &p:m){
            f[p.second]++;
        }

        int maxCount = 0;
        int freq = 0;
        for(int i=1;i<=100;i++){
            if(f[i] > maxCount || (f[i] == maxCount && i > freq)){
                maxCount = f[i];
                freq = i;
            }
        }
        string ans = "";
        for(auto &p:m){
            if(p.second == freq){
                ans += p.first;
            }
        }

        return ans;
    }
};
