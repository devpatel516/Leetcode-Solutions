class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int size = a.size();
        if (n == 0) return true;

        if (size == 1) {
            if (a[0] == 0) n--;
            return n <= 0;
        }
        if (a[0] == 0 && a[1] == 0) {
            a[0] = 1;
            n--;
        }
        for (int i = 1; i < size - 1; i++) {
            if (a[i] == 0 && a[i - 1] == 0 && a[i + 1] == 0) {
                a[i] = 1;
                n--;
                if (n == 0) return true;
            }
        }
        if (a[size - 1] == 0 && a[size - 2] == 0) {
            n--;
        }

        return n <= 0;
    }
};
