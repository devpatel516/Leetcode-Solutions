class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> ne,pe;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ne.push_back(nums[i]);
            }
            else{
                pe.push_back(nums[i]);
            }
        }
        if(pe.size()==0){
            return nums;
        }
        queue<int> q;
        for(int i=0;i<pe.size();i++){
            q.push(pe[i]);
        }
        while(k--){
            int t=q.front();
            q.pop();
            q.push(t);
        }

        // while(!q.empty()){
        //     cout<<q.front()<<" ";
        //     q.pop();
        // }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=q.front();
                q.pop();
            }
        }
        return nums;
    }
};