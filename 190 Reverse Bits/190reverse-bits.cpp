class Solution {
public:
    void helper(vector<int> &bits,int l,int h){
        if(l>=h){
            return ;
        }
        int mid=(l+h)/2;
        helper(bits,l,mid);
        helper(bits,mid+1,h);
        // int d=mid-l+1;
        // for(int i=0;i<d;i++){
        //     swap(bits[i+l],bits[mid+1+i]);
        // }
        for(int i=0;i<=mid-l;i++){
            swap(bits[i+l],bits[i+mid+1]);
        }
    }
    int reverseBits(int n) {
        vector<int> bits;
        for(int i=0;i<32;i++){
            bits.push_back((n>>i)&1);
        }
        helper(bits,0,bits.size()-1);
        unsigned long long ans=0;
        for(int i=0;i<32;i++){
            ans|=bits[i]<<i;
        }
        return ans;
    }
};