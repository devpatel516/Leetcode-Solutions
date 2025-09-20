class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left;
        left.push_back(1);
        int pl=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                left.push_back(++pl);
            }
            else{
                pl=1;
                left.push_back(1);
            }
        }
        int pr=1;
        vector<int> right(ratings.size());
        right[ratings.size()-1]=1;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                right[i]=++pr; 
            }
            else{
                pr=1;
                right[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<ratings.size();i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};