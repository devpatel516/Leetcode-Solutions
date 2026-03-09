class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //12 12 1 6 6
        //4 4 5
        //0 3 5 8 10
        //1 3 1 4 2
        //12 3 7 1 1

        //25 49 96
        //
        int n=position.size();
        vector<pair<int,int>> t(n);
        for(int i=0;i<n;i++){
            t[i]={position[i],speed[i]};
        }
        sort(t.begin(),t.end());
        vector<double> dist(n);
        for(int i=0;i<n;i++){
            dist[i]=(double)(target-t[i].first)/t[i].second;
        }
        stack<double> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(dist[i]);
            }
            else{
                if(st.top()>dist[i]){
                    st.push(dist[i]);
                }
                else{
                    while(!st.empty() && st.top()<=dist[i]){
                        st.pop();
                    }
                    st.push(dist[i]);
                }
            }
        }
        int ans=st.size();
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
    }
};