class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int i,sv=1;
        while(true){
        bool valid=true;
        int cs=sv;
        for(i=0;i<nums.size();i++){
            cs+=nums[i];
            if(cs<1){
                valid=false;
                break;
            }
        }
        if(valid){
            return sv;
        }
        sv++;
        }
        return 0;
    }
};