class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int j=1;
        // for(int i=0;i<n;i++){
        // }

        while(mp.size()!=n){
            if(mp.find(k-j)==mp.end()){
                sum+=j;
                mp[j]++;
                j++;
            }else{
                j++;
            }
        }
        return sum;
    }
};