class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto c:text){
            mp[c]++;
        }
        string temp="balloon";
        int c=0;
        bool valid=true;
        while(valid){
            for(auto k:temp){
                if(mp.count(k)){
                    mp[k]--;
                    if(mp[k]==0){
                        mp.erase(k);
                    }
                }else{
                    valid=false;
                    break;
                }
            }
            if(valid){
                c++;
            }
        }
        return c;
    }
};