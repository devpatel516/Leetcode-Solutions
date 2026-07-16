class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto c:arr){
            m[c]++;
        }
        set<int> st;
        for(auto k:m){
            if(st.contains(k.second)){
                return false;
            }
            st.insert(k.second);
        }
        return true;
    }
};