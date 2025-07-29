class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto c:piles){
            q.push(c);
        }
        while(k--){
            int temp=q.top();
            q.pop();
            temp=temp-temp/2;
            q.push(temp);
        }
        int c=0;
        while(!q.empty()){
            c+=q.top();
            q.pop();
        }
        return c;
    }
};