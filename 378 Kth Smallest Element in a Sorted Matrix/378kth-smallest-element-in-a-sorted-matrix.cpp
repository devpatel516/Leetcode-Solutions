class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int s=matrix.size()*matrix.size();
        priority_queue<int> q;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                q.push(matrix[i][j]);
            }
        }
        while(s>k){
            q.pop();
            s--;
        }
        return q.top();
    }
};