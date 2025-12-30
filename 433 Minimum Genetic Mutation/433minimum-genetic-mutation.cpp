class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        vector<char> c={'A','C','G','T'};
        queue<string> q;
        q.push(startGene);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string p=q.front();
                q.pop();
                if(p==endGene){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    char original=p[i];
                    for(int j=0;j<4;j++){
                        p[i]=c[j];
                        if(s.count(p)){
                            q.push(p);
                            s.erase(p);
                        }
                        p[i]=original;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};