class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string res="";
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            
            if(res.size()>=2 && res[res.size()-1]==temp.second && res[res.size()-2]==temp.second){
                if(pq.empty()){
                    break;
                }
                auto next=pq.top();
                pq.pop();
                res+=next.second;
                next.first--;
                if(next.first>0){
                    pq.push({next.first,next.second});
                }
                pq.push(temp);
            }else{
                res+=temp.second;
                temp.first--;
                if(temp.first>0){
                    pq.push({temp.first,temp.second});
                } 
            }
        }
        return res;
    }
};