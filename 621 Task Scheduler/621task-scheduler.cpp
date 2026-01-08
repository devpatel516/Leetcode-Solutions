class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto c:tasks){
            mp[c]++;
        }
        priority_queue<int> pq;
        for(auto c:mp){
            pq.push(c.second);
        }
        int time=0;

        while(!pq.empty()){
            vector<int> temp;
            int cycle=n+1;
            int i=0;

            while(i<cycle && !pq.empty()){
                int c=pq.top();
                pq.pop();

                c--;
                if(c>0){
                    temp.push_back(c);
                }
                time++;
                i++;
            }
            for(auto k:temp){
                pq.push(k);
            }
            if (pq.empty()) break;
            time+=(cycle-i);
        }
        return time;
    }
};