class Solution {
public:
    vector<int> nse(vector<int> &prices){
        int n=prices.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(prices[i]);
        }
        return ans;
    };
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> sub=nse(prices);
        vector<int> ans(prices.size());
        for(int i=0;i<prices.size();i++){
            if(sub[i]!=-1){
                ans[i]=prices[i]-sub[i];
            }
            else{
                ans[i]=prices[i];
            }
        }
        return ans;
    }
};