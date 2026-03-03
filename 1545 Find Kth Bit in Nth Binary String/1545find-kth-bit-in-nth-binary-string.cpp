class Solution {
public:
    string solve(string str,int i,int n){
        // if(i==1){
        //     return "0";
        // }
        if(i>n){
            return str;
        }
        string temp="";
        for(auto k:str){
            if(k=='0'){
                temp+='1';
            }
            else{
                temp+='0';
            }
        }
        reverse(temp.begin(),temp.end());
        return solve(str+"1"+temp,i+1,n);
    }
    char findKthBit(int n, int k) {
        string str=solve("0",1,n-1);
        return str[k-1];
    }
};