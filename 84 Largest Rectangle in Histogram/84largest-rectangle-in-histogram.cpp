class Solution {
public:
    vector<int> pse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=arr.size();
            }else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ps=pse(heights);
        vector<int> ns=nse(heights);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(ns[i]-ps[i]-1));
        }
        return ans;
    }
};