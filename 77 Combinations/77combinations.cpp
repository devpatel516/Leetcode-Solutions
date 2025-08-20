class Solution {
public:
    void func(int i,int n,int k,vector<int> arr,vector<vector<int>> &res){
        if(arr.size()==k){
            res.push_back(arr);
            return ;
        }
        if(i>n){
            return ;
        }
        for(int j=i;j<=n;j++){
            arr.push_back(j);
            func(j+1,n,k,arr,res);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        func(1,n,k,arr,res);
        return res;
    }
};