class Solution {
public:
    double time(vector<int> &dist,int speed){
        double s=0;
        for(int i=0;i<dist.size()-1;i++){
            //cout<<ceil((double)dist[i]/speed)<<" ";
            s+=ceil((double)dist[i]/speed);
        }
        //cout<<(double)dist[dist.size()-1]/speed<<" ";
        s+=(double)dist[dist.size()-1]/speed;
        return s;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
         int l=0;
         int r=1e9;
         int ans=INT_MAX;
         while(l<=r){
            double mid=(l+r)/2;
            double taken=time(dist,mid);
            if(taken>hour){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
         }
         if(ans==INT_MAX){
            return -1;
         }
         return ans;
    }
};