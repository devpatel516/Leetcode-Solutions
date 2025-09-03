class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
       vector<int> ans;
       for(int i=0;i<expression.size();i++){
            char c=expression[i];
            if(c=='+'||c=='-'||c=='*'){
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int> leftAns=diffWaysToCompute(left);
                vector<int> rightAns=diffWaysToCompute(right);
            for(int x:leftAns){
                for(int y:rightAns){
                    if(c=='+'){
                        ans.push_back(x+y);
                    }
                    else if(c=='-'){
                        ans.push_back(x-y);
                    }
                    else{
                        ans.push_back(x*y);
                    }
                }
            }
        }    
       }
        if(ans.empty()){
            ans.push_back(stoi(expression));
        } 
       return ans;
    }
};