class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        char a,b;
        for(auto c:s){
            st.push(c);
            if(st.size()>=2){
                if(!st.empty()){
                    b=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    a=st.top();
                    st.pop();
                }
                if((b=='B' && a=='A')||(b=='D' && a=='C')){
                    continue;
                }
                else{
                    st.push(a);
                    st.push(b);
                }
            }
        }
        return st.size();
    }
};