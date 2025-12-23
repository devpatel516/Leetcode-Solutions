class Solution {
public:
    int get_next(int n){
        int ans=0;
        while(n!=0){
            int d=n%10;
            ans+=d*d;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=get_next(n);

        while(fast!=1 && slow!=fast){
            slow=get_next(slow);
            fast=get_next(get_next(fast));
        }
        return fast==1;
    }
};