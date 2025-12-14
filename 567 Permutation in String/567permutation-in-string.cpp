class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m){
            return false;
        }

        vector<int> m1(26,0),m2(26,0);

        for(auto k:s1){
            m1[k-'a']++;
        }

        for(int i=0;i<m;i++){
            m2[s2[i]-'a']++;
            if(i>=n){
                m2[s2[i-n]-'a']--;
            }
            if(m1==m2){
                return true;
            }
        }
        return false;
    }
};