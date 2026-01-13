class Solution {
public:
    double below(double mid, vector<vector<int>>& squares) {
        double res = 0;
        for (int i = 0; i < squares.size(); i++) {
            double y = squares[i][1];
            double side = squares[i][2];
            if (mid <= y) {
                continue;
            } else if (mid >= y + side) {
                res += side * side;
            } else {
                res += (mid - y) * side;
            }
        }
        return res;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double totalarea = 0;
        double l = 2e9;
        double r = 0;

        for (auto& k : squares) {
            totalarea += (double)k[2] * k[2];
            l = min(l, (double)k[1]);
            r = max(r, (double)k[1] + k[2]);
        }

        for (int i = 0; i < 100; i++) {
            double mid = l + (r - l) / 2;
            if (below(mid, squares) >= totalarea / 2.0) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};