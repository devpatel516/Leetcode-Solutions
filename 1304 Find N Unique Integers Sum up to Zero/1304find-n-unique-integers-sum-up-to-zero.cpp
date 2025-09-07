class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int left, right;
        left = 0;
        right = n - 1;
        int val = n / 2;
        if (n % 2 == 0) {
            while (left < right) {
                if (left != right) {
                    ans[left] = -val;
                    ans[right] = val;
                    left++;
                    right--;
                    val--;
                } else {
                    ans[left] = 0;
                }
            }
        }
            else {
                while(left<right){
                ans[left] = -val;
                ans[right] = val;
                left++;
                right--;
                val--;
                }
            }
            return ans;
        }
    };