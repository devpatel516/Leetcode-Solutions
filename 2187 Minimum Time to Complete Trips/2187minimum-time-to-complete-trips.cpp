class Solution {
public:
    long long solve(vector<int> &time,long long t){
        long long trips=0;
        for(int i=0;i<time.size();i++){
            trips+=(t/time[i]);
        }
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long r=1e14;
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long trips=solve(time,mid);
            if(trips>=totalTrips){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};