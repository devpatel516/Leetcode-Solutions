class Solution {
public:
    long long smallestNumber(long long num) {
        if(num>0){
            string x=to_string(num);

            sort(x.begin(),x.end());
            int idx=0;
            while(x[idx]=='0'){
                idx++;
            }
            swap(x[idx],x[0]);
            long long res=stoll(x);
            return res;
        }
        else{
            num=1LL*-1*num;
            string x=to_string(num);
            sort(x.rbegin(),x.rend());
            long long res=stoll(x);
            return 1LL*-1*res;
        }
    }
};