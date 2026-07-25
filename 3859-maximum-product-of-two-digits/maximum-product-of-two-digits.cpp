class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n!=0){
            int r=n%10;
            n/=10;
            pq.push(r);
        }
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        return a*b;
    }
};