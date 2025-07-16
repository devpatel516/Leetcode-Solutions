class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto ch:s){
            m[ch]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto k:m){
            q.push({k.second,k.first});
        }
        string res="";
        while(!q.empty()){
            int temp=q.top().first;
            while(temp>0){
                res+=q.top().second;
                temp--;
            }
            q.pop();
        }
        return res;
    }
};