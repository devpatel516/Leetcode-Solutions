class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prev=st.top();
                st.pop();
                res[prev]=i-prev;
            }
            st.push(i);
        }
        // st.push({temperatures[0],0});
        // for(int i=1;i<n;i++){
        //     if(st.top().first<temperatures[i]){
        //         int temp;
        //         if(!st.empty()){
        //             temp=st.top().second;
        //         }
        //         st.push({temperatures[i],i});
        //         res[i-1]=abs(temp-i);
        //     }
        //     else{
        //         while(!st.empty() && st.top().first>temperatures[i]){
        //             st.pop();
        //         }
        //         int temp;
        //         if(!st.empty()){
        //             temp=st.top().second;
        //         }
        //         st.push({temperatures[i],i});
        //         res[i-1]=abs(temp-i);
        //     }
        // }
        return res;
    }
};