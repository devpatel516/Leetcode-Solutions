class Solution {
public:
    string trim(string temp){
        string res="";
        int j=0;
            while(j<temp.size()){
                if(temp[j]=='0'){
                    j++;
                }
                else{
                    res+=temp.substr(j);
                    break;
                }
            }
        return res;
    } 
    int bstoi(string s){
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans=(ans*2+(s[i]-'0'));
        }
        return ans;
    }
    int maxGoodNumber(vector<int>& nums) {
        string a="",b="",c="";
        bitset<8> x(nums[0]);
        a=x.to_string();
        bitset<8> y(nums[1]);
        b=y.to_string();
        bitset<8> z(nums[2]);
        c=z.to_string();
        a=trim(a);
        b=trim(b);
        c=trim(c);
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;
        vector<string> combinations={a+b+c,a+c+b,b+a+c,b+c+a,c+a+b,c+b+a};    
        int ans=0;
        for(int i=0;i<6;i++){
            ans=max(ans,bstoi(combinations[i]));
        }
        return ans;
    }
};