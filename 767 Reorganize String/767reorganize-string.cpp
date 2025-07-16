class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(auto ch:s){
            m[ch]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto k:m){
            q.push({k.second,k.first});
        }
        string str="";                          // 2,a
        while(q.size()>1){        // 1,b
            char a=q.top().second;
            int af=q.top().first;
            str+=a;
            af--;
            q.pop();
            char b=q.top().second;
            int bf=q.top().first;
            str+=b;
            bf--;
            q.pop();
            if(af>0){
                q.push({af,a});
                }
            if(bf>0){
                q.push({bf,b});
            }
        }
        while(!q.empty()){
            int temp=q.top().first;
            char tempc=q.top().second;
            if(temp==1){
                str+=tempc;
                q.pop();
            }
            else{
                return "";
            }
        }
        return str;
    }
};