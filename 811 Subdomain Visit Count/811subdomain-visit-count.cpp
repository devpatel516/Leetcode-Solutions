class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        unordered_map<string,int> mp;
        for(auto k:cpdomains){
            string counts="";
            for(int i=0;i<k.size();i++){
                if(k[i]==' '){
                    break;
                }else{
                    counts+=k[i];
                }
            }
            string a="";
            for(int i=counts.size()+1;i<k.size();i++){
                a+=k[i];
            }
            for(int i=0;i<a.size();i++){
                if(a[i]=='.'){
                    mp[a.substr(i+1)]+=stoi(counts);
                }
            }
            mp[a]+=stoi(counts);
        }
        for(auto k:mp){
            string temp;
            temp+=to_string(k.second);
            temp+=" ";
            temp+=k.first;
            res.push_back(temp);
        }
        return res;
    }
};