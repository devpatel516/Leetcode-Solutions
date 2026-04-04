class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans="";
        int cols=encodedText.size()/rows;
        vector<vector<char>> mat(rows,vector<char>(cols,' '));
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(encodedText[k]!=' '){
                    mat[i][j]=encodedText[k];
                }
                k++;
            }
        }
        cout<<mat.size()<<" "<<mat[0].size()<<endl;
        for(int c=0;c<cols;c++){
            int i=0,j=c;

            while(i<rows && j<cols){
                ans+=mat[i][j];
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};