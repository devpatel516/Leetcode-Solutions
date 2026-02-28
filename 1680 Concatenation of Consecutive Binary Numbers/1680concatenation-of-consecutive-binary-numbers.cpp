class Solution {
public:
    int concatenatedBinary(int n) {
        string og="";
        for(int i=1;i<=n;i++){
            bitset<20> b(i);
            string temp=b.to_string();
            // cout<<temp<<endl;
            int j=0;
            while(j<temp.size()){
                if(temp[j]=='0'){
                    j++;
                }
                else{
                    og+=temp.substr(j);
                    break;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<og.size();i++){
            ans=(ans*2+(og[i]-'0'))%1000000007LL;
        }
        return ans;
    }
};