class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int c=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]!=-1 && fruits[i]<=baskets[j]){
                    baskets[j]=-1;
                    c++;
                    break;
                }
            }
        }
        return fruits.size()-c;
    }
};