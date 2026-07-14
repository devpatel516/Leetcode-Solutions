class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        int l=to_string(low).size();
        int h=to_string(high).size();
        vector<int> ans;
        for(int i=l;i<=h;i++){
            for(int j=0;j+i<=s.size();j++){
                int k=stoi(s.substr(j,i));
                if(k>=low && k<=high){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};