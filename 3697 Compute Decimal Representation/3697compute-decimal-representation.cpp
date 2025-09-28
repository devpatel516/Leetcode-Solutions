class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long m=1;
        while(n!=0){
            int d=n%10;
            n/=10;
            if(d!=0){
                ans.push_back(d*m);
            }
            m*=10;
        }
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};