class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        //sort(words.begin(),words.end());
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=k){
                mp[words[i].substr(0,k)]++;
            }
        }
        cout<<mp.size()<<endl;
        int ans=0;
        for(auto k:mp){
            if(k.second>=2){
                ans++;
            }
        }
        return ans;
    }
};