class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int c=0;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            auto [count,ind]=q.front();
            q.pop();
            count--;
            c++;
            if(count>0){
                q.push({count,ind});
            }
            if(ind==k && count==0){
                return c;
            }
        }
        return c;
    }
};