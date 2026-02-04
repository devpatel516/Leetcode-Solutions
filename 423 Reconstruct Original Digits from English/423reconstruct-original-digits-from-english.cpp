class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        vector<int> temp(10);
        temp[0]=mp['z'];
        temp[2]=mp['w'];
        temp[4]=mp['u'];
        temp[6]=mp['x'];
        temp[8]=mp['g'];
        temp[1]=mp['o']-temp[0]-temp[2]-temp[4];
        temp[3]=mp['h']-temp[8];
        temp[5]=mp['f']-temp[4];
        temp[7]=mp['s']-temp[6];
        temp[9]=mp['i']-temp[5]-temp[6]-temp[8];
        string ans="";
        for(int i=0;i<temp.size();i++){
            while(temp[i]--){
                ans+=to_string(i);
            }
        }
        return ans;
    }
};