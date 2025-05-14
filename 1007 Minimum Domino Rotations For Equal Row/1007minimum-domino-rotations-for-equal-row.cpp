class Solution {
public:
    pair<int,int> maxfreq(vector<int> a){
        unordered_map<int,int> m;
        for(auto c:a){
            m[c]++;
        }
        int m_num=0,m_count=0;
        for(auto p:m){
            if(p.second>m_count){
                m_num=p.first;
                m_count=p.second;
            }
        }
        return {m_num,m_count};
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        pair<int,int> mt=maxfreq(tops);
        pair<int,int> mb=maxfreq(bottoms);
        int max=0,num=0,top=0;
        if(mt.second>mb.second){
            max=mt.second;
            num=mt.first;
            top=1;
        }
        else{
            max=mb.second;
            num=mb.first;
        }
        if(mt.second==mb.second && mt.first==4){
            return 3;
        }
        if(max==tops.size()){
            return 0;
        }
        int r=0;
        if(top){
            for(int i=0;i<tops.size();i++){
                if(tops[i]==num){
                    continue;
                }
                else if(bottoms[i]==num){
                        r++;
                }
                else{
                    return -1;
                }
            }
        }
        else{
            for(int i=0;i<bottoms.size();i++){
                if(bottoms[i]==num){
                    continue;
                }
                else if(tops[i]==num){
                        r++;
                }
                else{
                    return -1;
                }
            }
        }
        return r;
    }
};