class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> t(26,0);
        for(int i=0;i<s.size();i++){
            t[s[i]-'a']+=1;
        }
        int mv=INT_MIN;
        int mc=INT_MIN;
        for (int i=0;i<t.size();i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                if(t[i]>mv){
                    mv=t[i];
                }
            }
            else{
                if(t[i]>mc){
                    mc=t[i];
                }
            }
        }
        return mc+mv; 
    }
};