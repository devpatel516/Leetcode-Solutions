class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0;
        vector<int> arr(nums1.size()+nums2.size());
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                arr[k]=nums1[i];
                i++;
                k++;
            }
            else{
                arr[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<nums1.size()){
            arr[k]=nums1[i];
            i++;
            k++;
        }
        while(j<nums2.size()){
            arr[k]=nums2[j];
            j++;
            k++;
        }
        int n=arr.size();
        double median;
        if(n%2==1){
            median=arr[n/2];
        }
        else{
            median=(arr[n/2 -1]+arr[n/2])/2.0;
        }
        return median;
    }
};