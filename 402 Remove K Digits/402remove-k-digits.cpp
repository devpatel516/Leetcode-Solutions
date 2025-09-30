class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        cout<<num.size()<<endl;
        int og=k;
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()-'0'>num[i]-'0' && k!=0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        cout<<k<<endl;
        if(k==og){
            return num.substr(0,num.size()-k);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        string t=ans.substr(i);
        if(t==""){
            return "0";
        }
        else{
            return t;
        }
    }
};