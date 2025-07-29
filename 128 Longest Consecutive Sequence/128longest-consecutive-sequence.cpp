class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(),a.end());
        if(a.size()==0){
            return 0;
        }
        int c=1;
    int maxi=1;
    for(int i=1;i<a.size();i++){  
        if(a[i]==a[i-1]){
            continue;
        }     
        else if(a[i]==a[i-1]+1){  
            c++;
        }
        else{
            c=1;
        }
        maxi=max(maxi,c);
    }
    return maxi;
    }
};