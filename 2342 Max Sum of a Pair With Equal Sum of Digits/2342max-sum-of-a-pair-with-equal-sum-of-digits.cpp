class Solution {
public:
    int digitsum(int d){
        int s=0;
        while(d>0){
            s+=d%10;
            d/=10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> digits;
        int m=-1;
        for(auto n:nums){
            int sd=digitsum(n);
            if(digits.count(sd)){
                m=max(m,digits[sd]+n);
                digits[sd]=max(digits[sd],n);
            }
            else{
                digits[sd]=n;
            }
        }
        return m;
    }
};