class Solution {
public:
    int totalMoney(int n) {
        int s=1;
        int loop=n/7;
        int remain=n%7;
        int ans=0;

        for(int i=1;i<=loop;i++){
            for(int j=s;j<s+7;j++){
                ans+=j;
            }
            s++;
        }
        for(int i=s;i<s+remain;i++){
            ans+=i;
        }
        return ans;
    }
};