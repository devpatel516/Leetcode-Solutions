class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> res(houses.size(), INT_MAX);
        int h = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (h < heaters.size() && heaters[h] < houses[i]) {
                h++;
            }
            if (h < heaters.size()) {
                res[i] = heaters[h] - houses[i];
            }
            if (h > 0) {
                res[i] = min(res[i], houses[i] - heaters[h - 1]);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};
