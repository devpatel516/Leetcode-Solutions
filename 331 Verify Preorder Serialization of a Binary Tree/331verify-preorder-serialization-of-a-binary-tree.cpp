class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots=1;
        vector<string> tokens;
        string token;
        stringstream ss(preorder);

        while(getline(ss,token,',')){
            tokens.push_back(token);
        }
        if(tokens[0]=="#" && tokens.size()>1){
            return false;
        }
        for(int i=0;i<tokens.size();i++){
            if (slots == 0) return false;
            if(tokens[i]=="#"){
                slots-=1;
            }
            else{
                slots-=1;
                slots+=2;
            }
        }
        return slots==0;
    }
};