class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i=0;
        string str="";
        for(auto c:s){
            if(!st.empty() && c==st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            str=st.top()+str;
            st.pop();
        }
        return str;
    }
};