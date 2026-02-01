class Solution {
public:
    int countMonobit(int n) {
        int ans=0;
        for(int i=0;i<=n;i++){
            string temp=format("{:b}",i);
            bool val=true;
            for(int i=1;i<temp.size();i++){
                if(temp[i-1]!=temp[i]){
                    val=false;
                }
            }
            if(val){
                ans++;
            }
        }
        
        return ans;
    }
};