class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }

        map<int,int> mp;
        for(auto x:hand){
            mp[x]++;
        }

        while(!mp.empty()){
            auto x=mp.begin();
            int st=x->first;
            for(int i=st;i<st+groupSize;i++){
                if(!mp.count(i)){
                    return false;
                }
                mp[i]--;
                if(mp[i]==0){
                    mp.erase(i);
                }
            }
        }
        return true;
    }
};