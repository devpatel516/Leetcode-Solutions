class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int,int>> ans;
        for (int i = 0; i < n; i++) {
            sort(mat[i].begin(),mat[i].end());
            int l = upper_bound(mat[i].begin(), mat[i].end(), 0) - mat[i].begin();
            ans.push_back({n-l, i});
        }
        sort(ans.begin(), ans.end());
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(ans[i].second);
        }
        return result;
    }
};
