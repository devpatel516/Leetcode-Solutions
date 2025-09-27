class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        string temp=s;
        if(n==k){
            return 1;
        }
        set<pair<int,int>> ans;
        vector<int> x(n+1,0);
        vector<int> y(n+1,0);

        for(int i=0;i<n;i++){
            x[i+1]=x[i];
            y[i+1]=y[i];

            if(s[i]=='U'){
                y[i+1]++;
            }
            else if(s[i]=='D'){
                y[i+1]--;
            }
            else if(s[i]=='L'){
                x[i+1]--;
            }
            else if(s[i]=='R'){
                x[i+1]++;
            }
        }

        for(int j=0;j+k<=n;j++){
            int nx=x[n]-(x[j+k]-x[j]);
            int ny=y[n]-(y[j+k]-y[j]);
            cout<<nx<< " " <<ny<<endl;
            ans.insert({nx,ny});
        }
        return ans.size();
    }
};