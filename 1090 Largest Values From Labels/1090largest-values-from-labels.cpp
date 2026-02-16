class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        if(numWanted==0){
            return 0;
        }
        int n=values.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i].first=values[i];
            a[i].second=labels[i];
        }
        sort(a.rbegin(),a.rend());
        int maxi=*max_element(labels.begin(),labels.end());
        vector<int> lu(maxi+1);
        for(auto it:labels){
            lu[it]=useLimit;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(lu[a[i].second]!=0){
                ans+=a[i].first;
                numWanted--;
                if(numWanted==0){
                    break;
                }
                lu[a[i].second]--;
            }
        }
        return ans;
    }
};