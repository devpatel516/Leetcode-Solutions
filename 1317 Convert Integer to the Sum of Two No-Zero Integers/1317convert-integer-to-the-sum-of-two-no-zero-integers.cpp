class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        if(n<=2){
            ans.push_back(1);
            ans.push_back(1);
            return ans;
        }
        for(int i=2;i<10e5;i++){
            int x=n-i;
            string a=to_string(x);
            string b=to_string(i);
            if(a.contains('0') || b.contains('0')){
                continue;
            }
            else{
                ans.push_back(x);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};