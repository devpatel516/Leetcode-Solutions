class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int maxE=*max_element(arr.begin(),arr.end());
        vector<int> count(maxE+1,0);
        for(auto c:arr){
            count[c]++;
        }
        int n=arr.size();
        float percent=(25.0/100)*n;
        int ans=0;
        for(int ele=1;ele<=maxE;ele++){
           if(count[ele]>=percent){
            ans=ele;
           } 
        }  
        return ans;
    }
};