class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1){
            return 0;
        }
        if(n==2){
            if(s[0]>s[1]){
                return -1;
            }
            else{
                return 0;
            }
        }
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s){
            return 0;
        }        
        string a=s;
        string b=s;
        sort(a.begin(),a.begin()+n-1);
        sort(b.begin()+1,b.end());
        if(a==temp || b==temp){
            return 1;
        }
        sort(a.begin()+1,a.end());
        sort(b.begin(),b.begin()+n-1);
        if(a==temp||b==temp){
            return 2;
        }
        else{
            return 3;
        }
    }
};