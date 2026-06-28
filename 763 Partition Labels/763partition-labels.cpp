class Solution {
public:
    vector<int> partitionLabels(string s) {
        //                    1 1 1 1 1 1 1 1 1 1 2 2 2 2 
        //0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3
        //a b a b c b a c a d e f e g d e h i j h k l i j

        /*
        a-[0 8]
        b-[1 5]
        c-[4 7]
        d-[9 14]
        e-[10 15]
        f-[11 11]
        g-[13 13]
        h-[16 19]
        i-[17 22]
        j-[18 23]
        k-[20 20]
        l-[21 21]
        */
        map<char,int> st;
        map<char,int> ed;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st[s[i]]=i;
            }
        }
        for(int i=0;i<s.size();i++){
            ed[s[i]]=i;
        }        
        vector<vector<int>> intervals;
        for(char c='a';c<='z';c++){
            if(st.count(c)){    
                intervals.push_back({st[c],ed[c]});
            }
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(auto x:intervals){
            if(merged.empty() || x[0]>merged.back()[1]){
                merged.push_back(x);
            }else{
                merged.back()[1]=max(merged.back()[1],x[1]);
            }
        }
        vector<int> ans;
        for(int i=0;i<merged.size();i++){
            ans.push_back(merged[i][1]-merged[i][0]+1);
        }
        return ans;
    }
};