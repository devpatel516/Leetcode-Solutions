class Solution {
public:
    bool isPalindromic(string s) {
        string temp="";
        for(auto c:s){
            int ascii=c;
            bitset<8> a(c);
           // cout<<a<<endl;
            temp=temp+a.to_string();
        }
        string temp2=temp;
        reverse(temp2.begin(),temp2.end());
        return temp==temp2?true:false;
    }
};