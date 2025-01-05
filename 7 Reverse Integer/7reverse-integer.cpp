class Solution {
public:
    int reverse(int x) {
        int s = 0, d,o=x;
        bool negative = false;
        x=abs(x);
        while (x > 0) {
            d = x % 10;
            x = x / 10;
            if ((s > INT_MAX / 10) || (s < INT_MIN / 10)) {
                return 0;
            }
            s = s * 10 + d;
        }
        if (o < 0) {
                x = x * (-1);
                negative = true;
            }
        if (negative) {
            return -s;
        }
        return s;
    }
};