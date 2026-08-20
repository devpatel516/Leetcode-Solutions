class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int ans=INT_MIN;
        unordered_map<char,int> mp;
        while(right<n){
            mp[s[right]]++;
            //cout<<s[right]<<" "<<mp[s[right]]<<endl;
            while(mp.find(s[right])!=mp.end() && mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};