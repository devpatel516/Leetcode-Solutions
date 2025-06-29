class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto c:tokens){
            if(c!="+" && c!="-" && c!="*" && c!="/"){
                s.push(c);
            }
            else{
                int operand2=stoi(s.top());
                s.pop();
                int operand1=stoi(s.top());
                s.pop();
                int ans;
                if(c=="+"){
                    ans=operand1+operand2;
                }
                else if(c=="-"){
                    ans=operand1-operand2;
                }
                else if(c=="*"){
                    ans=operand1*operand2;
                }
                else if(c=="/"){
                    ans=operand1/operand2;
                }
                s.push(to_string(ans));
            }
        }
        return stoi(s.top());
    }
};