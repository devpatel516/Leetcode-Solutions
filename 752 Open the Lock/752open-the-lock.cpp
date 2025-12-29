class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> d(deadends.begin(),deadends.end());
        if (d.count("0000")) return -1;
        unordered_set<string> vis;
        int ans=0;
        q.push("0000");
        vis.insert("0000");

        while(!q.empty()){
            int size=q.size();
            while(size--){
                string p=q.front();
                q.pop();

                if(p==target){
                    return ans; 
                }
                for(int i=0;i<4;i++){
                    string t1=p,t2=p;
                    t1[i]=(p[i]=='9')?'0':p[i]+1;
                    t2[i]=(p[i]=='0')?'9':p[i]-1;

                    if(!d.count(t1) && !vis.count(t1)){
                        vis.insert(t1);
                        q.push(t1);
                    }

                    if(!d.count(t2) && !vis.count(t2)){
                        vis.insert(t2);
                        q.push(t2);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};