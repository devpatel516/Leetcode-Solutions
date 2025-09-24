class Solution {
public:
    vector<int> nse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=arr.size();
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    };
    vector<int> pse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    };
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> ns=nse(arr);
        vector<int> ps=pse(arr);
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int l=i-ps[i];
            int r=ns[i]-i;
            total=(total+(r*l*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};