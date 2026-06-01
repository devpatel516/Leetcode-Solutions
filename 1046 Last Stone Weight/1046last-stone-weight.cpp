class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto k:stones){
            pq.push(k);
        }
        if(pq.empty()){
            return 0;
        }
        while(pq.size()!=1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a<b){
                b=b-a;
                pq.push(b);
            }else{
                a=a-b;
                pq.push(a);
            }
        }
        return pq.top();
    }
};
