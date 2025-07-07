class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mp;
        for (int i = 0; i < score.size(); i++) {
            mp[score[i]] = i;  
        }

        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());

        vector<string> ans(score.size());
        for (int i = 0; i < sorted.size(); i++) {
            int idx = mp[sorted[i]];
            if (i == 0) ans[idx] = "Gold Medal";
            else if (i == 1) ans[idx] = "Silver Medal";
            else if (i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i + 1);
        }

        return ans;
    }
};
