class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxE=*max_element(costs.begin(),costs.end());
        vector<int> count(maxE+1);
        for(auto c:costs){
            count[c]++;
        }
        int ans=0;
        for(int price=1;price<=maxE;price++){
            int totalBuy=min(count[price],coins/price);
            if(coins<price){
                break;
            }
            coins-=totalBuy*price;
            ans+=totalBuy;
        }
        return ans;
    }
};
// 1