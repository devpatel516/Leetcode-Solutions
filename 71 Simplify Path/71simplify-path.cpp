class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string s;
        while(getline(ss,s,'/')){
            if(s=="" || s=="."){
                continue;
            }

            if(s==".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(s);
            }
        }
        vector<string> temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        string result = "";
        for(auto x : temp) {
            result += "/" + x;
        }
        return result.empty() ? "/" : result;
    }
};