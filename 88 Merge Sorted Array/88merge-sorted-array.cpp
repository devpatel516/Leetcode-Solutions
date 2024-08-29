#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left,right,l=0;
        left=0;
        right=m+n-1;
        while(left<=right){
            if(nums1[left]!=0){
                left++;
            }
            else if(l<n){
                nums1[left]=nums2[l];
                l++;
                left++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};