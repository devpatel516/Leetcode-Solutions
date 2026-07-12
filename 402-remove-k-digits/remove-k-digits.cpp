class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int t=0;
        if(k==1 && num.size()==1){
            return "0";
        }
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && num[i]-'0'<st.top()){
                k--;
                st.pop();
            }
            if(st.empty() && num[i]-'0'==0){
                continue;
            }
            st.push(num[i]-'0');
        }
        while(k > 0 && !st.empty()) {
           st.pop();
        k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top()+'0';
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res==""){
            return "0";
        }
        return res;
    }
};