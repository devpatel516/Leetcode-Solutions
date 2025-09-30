class Solution {
public:
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
    }

    vector<int> pge(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
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
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nge(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
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
    }
    long long small(vector<int> &nums,vector<int> &pse,vector<int> &nse){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long l=i-pse[i];
            long long r=nse[i]-i;
            ans+=(1LL*l*r*nums[i]);
        }
        return ans;
    }

    long long large(vector<int> &nums,vector<int> &pge,vector<int> &nge){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long l=i-pge[i];
            long long r=nge[i]-i;
            ans+=(1LL*l*r*nums[i]);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<int> ps=pse(nums);
        vector<int> ns=nse(nums);
        vector<int> pg=pge(nums);
        vector<int> ng=nge(nums);

        return large(nums,pg,ng)-small(nums,ps,ns);
    }
};