class Solution {
public:
    int maxArea(vector<int>& height) {
     int ma=0;
     int left=0;
     int right=height.size()-1;
     while(left<right){
            int area=abs(left-right)*min(height[left],height[right]);
            ma=max(area,ma);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
     return ma;
    }
};