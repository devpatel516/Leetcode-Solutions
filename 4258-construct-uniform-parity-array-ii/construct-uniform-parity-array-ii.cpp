class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size()==1){
            return true;
        }
        int mini=*min_element(nums1.begin(),nums1.end());
        if(mini%2!=0){
            return true;
        }else{
        vector<int> odd,even;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                even.push_back(nums1[i]);
            }else{
                odd.push_back(nums1[i]);
            }
        }
        int co=odd.size();
        int ce=even.size();
        if(ce==nums1.size()){
            return true;
        }else{
            return false;
        }
        }
        return false;
    }
};