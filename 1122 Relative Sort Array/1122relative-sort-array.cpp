class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp; 
        for (auto t : arr1) {
            mp[t]++;
        }
        int i = 0;
        for (auto t : arr2) {
            while (mp[t]-- > 0) { 
                arr1[i++] = t;
            }
        }
        for (auto t : mp) {
            int freq = t.second; 
            while (freq-- > 0) {
                arr1[i++] = t.first;
            }
        }
        return arr1;
    }
};
