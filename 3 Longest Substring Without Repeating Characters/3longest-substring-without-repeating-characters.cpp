class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            if(!st.count(s[r])){
                st.insert(s[r]);
                ans=max(ans,r-l+1);
            }
            else{
                while(st.count(s[r])){
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
            r++;
        }
        return ans;
    }
};