class Solution {
public:
    int getLucky(string s, int k) {
        string number="";
        char x;
        for(auto x:s){
            number+=to_string(x-'a'+1);
        }
        while(k-->0){
            int temp=0;
        for(auto x:number){
            temp+=x-'0';
        }
        number=to_string(temp);
        }
        return stoi(number);
    }
};