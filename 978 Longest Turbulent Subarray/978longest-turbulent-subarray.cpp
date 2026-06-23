class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res=0;
        int c=0;
        int flip=-1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                if(flip==0){
                    c++;
                }else{
                    c=1;
                }
                flip=1;
            }else if(arr[i]<arr[i+1]){
                if(flip==1){
                    c++;
                }else{
                    c=1;
                }
                flip=0;
            }else{
                c=0;
                flip=-1;
            }
            res=max(res,c);
        }   
        return res+1;
    }
};