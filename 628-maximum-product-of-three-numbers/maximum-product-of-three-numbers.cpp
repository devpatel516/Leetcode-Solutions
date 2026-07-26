class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> p1;
        priority_queue<int,vector<int>,greater<int>> p2;
        int ma1,ma2,ma3,mi1,mi2,mi3;
        for(auto k:nums){
            p1.push(k);
            p2.push(k);
        }
        ma1=p1.top();
        p1.pop();
        mi1=p2.top();
        p2.pop();

        ma2=p1.top();
        p1.pop();
        mi2=p2.top();
        p2.pop();

        ma3=p1.top();
        p1.pop();
        mi3=p2.top();
        p2.pop();
        int ans=max(ma1*ma2*ma3,mi1*mi2*ma1);
        return ans;
    }
};