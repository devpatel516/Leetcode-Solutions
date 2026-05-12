/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mount=0;
        int l=0;
        int r=mountainArr.length()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                mount=mid+1;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //cout<<mount<<endl;
        if(mountainArr.get(mount)==target){
            return mount;
        }
        int l1=0;
        int r1=mount;
        while(l1<=r1){
            int mid1=(l1+r1)/2;
            if(mountainArr.get(mid1)<target){
                l1=mid1+1;
            }
            else if(mountainArr.get(mid1)>target){
                r1=mid1-1;
            }
            else{
                return mid1;
            }
        }
        int l2=mount;
        int r2=mountainArr.length()-1;
        while(l2<=r2){
            int mid2=(l2+r2)/2;
            if(mountainArr.get(mid2)<target){
                r2=mid2-1;
            }
            else if(mountainArr.get(mid2)>target){
                l2=mid2+1;
            }
            else{
                return mid2;
            }
        }
        return -1;
    }
};