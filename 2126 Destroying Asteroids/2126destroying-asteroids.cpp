class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        //3 5 9 19 21
        long long temp=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=temp){
                temp+=asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};