class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int maxi=-1;
        for(int i=1;i<num.size()-1;i++){
            if(num[i]==num[i-1] && num[i]==num[i+1] && maxi<num[i]){
                ans="";
                ans+=num[i-1];
                ans+=num[i];
                ans+=num[i+1];
                maxi=max(-1,num[i]-0);
            }
        }
        return ans;   
    }
};