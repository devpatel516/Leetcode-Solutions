class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n=num1.size();
        int m=num2.size();
        vector<int> res(m+n,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int temp=(num1[i]-'0')*(num2[j]-'0');
                int sum=temp+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }

        string result="";

        for(auto x:res){
            if(result.empty() && x==0){
                continue;
            }
            result+=to_string(x);
        }
        if(result==""){
            return "0";
        }
        return result;
    }
};