class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0),ans(n);
        for(auto k:bookings){
            int l=k[0]-1;
            int r=k[1]-1;
            int seat=k[2];

            diff[l]+=seat;
            if(r+1<n){
                diff[r+1]-=seat;
            }
        }
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
            ans[i]=diff[i]+ans[i-1];
        }
        return ans;
    }
};