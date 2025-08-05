class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maf=0,mif=INT_MAX;
                for(auto k:freq){
                    if(k>0){
                        maf=max(maf,k);
                        mif=min(mif,k);
                    }
                }
                sum+=(maf-mif);
            }
        }
        return sum;
    }
};