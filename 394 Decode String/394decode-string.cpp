class Solution {
public:
    string decodeString(string s) {
        stack<int> ns;
        stack<string> ss;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                ns.push(num);
                i--;
            }else if(s[i]=='['){
                ss.push(string(1,s[i]));
            }
            else if(s[i]==']'){
                string temp="";
                while(!ss.empty() && ss.top()!="["){
                    temp=ss.top()+temp;
                    ss.pop();
                }
                ss.pop();
                int k=ns.top();
                ns.pop();
                string r="";
                while(k--){
                    r+=temp;
                }
                ss.push(r);
            }
            else{
                ss.push(string(1,s[i]));
            }
        }
        string ans="";
        while(!ss.empty()){
            ans=ss.top()+ans;
            ss.pop();
        }
        return ans;
    }
};