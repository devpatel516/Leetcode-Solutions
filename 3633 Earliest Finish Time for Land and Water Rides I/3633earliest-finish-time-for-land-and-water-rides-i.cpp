class Solution {
public:
    int helper(vector<int> &a,vector<int> &ad,vector<int> &b,vector<int> &bd){
        int finish=INT_MAX;

        for(int i=0;i<a.size();i++){
            finish=min(finish,a[i]+ad[i]);
        }

        int answer=INT_MAX;
        for(int i=0;i<b.size();i++){
            if(finish>b[i]){
                answer=min(answer,finish+bd[i]);
            }
            else{
                answer=min(answer,b[i]+bd[i]);
            }
        }

        return answer;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirst=helper(landStartTime,landDuration,waterStartTime,waterDuration);

        int waterFirst=helper(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(landFirst,waterFirst);
    } 
};