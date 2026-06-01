class Solution {
public:
    int Euclidean(vector<int> point){
        return (point[0] * point[0]) + (point[1] * point[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<int,vector<int>>,
        vector<pair<int,vector<int>>>,
        greater<pair<int,vector<int>>>
        > pq;
        
        for(auto p:points){
            pq.push({Euclidean(p),p});
        }
        vector<vector<int>> res;
        while(k-- && !pq.empty()){
            auto temp=pq.top();
            pq.pop();
            res.push_back(temp.second);
        }
        return res;
    }
};
