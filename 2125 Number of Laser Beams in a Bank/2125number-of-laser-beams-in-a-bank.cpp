class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int> f;
        // if(n==1){
        //     return 0;
        // }
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    k++;
                }
            }
            if(k>0){
                f.push_back(k);
            }
        }
        int ans=0;
        for(int i=1;i<f.size();i++){
            ans+=f[i-1]*f[i];
        }
        return ans;
    }
};