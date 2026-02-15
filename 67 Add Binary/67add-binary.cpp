class Solution {
public:
    string addBinary(string a, string b) {
        int n=max(a.size(),b.size());
        string t="";
        if(a.size()!=n){
            int x=n-a.size();
            while(x--){
                t+="0";
            }
            t+=a;
            a=t;
        }
        else{
            int x=n-b.size();
            while(x--){
                t+="0";
            }
            t+=b;
            b=t;
        }
        int c=0;
        vector<char> ans;
        for(int i=n-1;i>=0;i--){
            int x=a[i]-'0';
            int y=b[i]-'0';
            if(x==0 && y==0 && c==0){
                ans.push_back('0');
                c=0;
            }else if(x==0 && y==0 && c==1){
                ans.push_back('1');
                c=0;
            }else if(x==0 && y==1 && c==0){
                ans.push_back('1');
                c=0;
            }else if(x==0 && y==1 && c==1){
                ans.push_back('0');
                c=1;
            }else if(x==1 && y==0 && c==0){
                ans.push_back('1');
                c=0;
            }else if(x==1 && y==0 && c==1){
                ans.push_back('0');
                c=1;
            }else if(x==1 && y==1 && c==0){
                ans.push_back('0');
                c=1;
            }else if(x==1 && y==1 && c==1){
                ans.push_back('1');
                c=1;
            }
        }
        if(c==1){
            ans.push_back('1');
        }
        string res="";
        for(auto k:ans){
            res+=k;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};