class Solution {
public:
    int compress(vector<char>& chars) {
        int c=1;
        int l=0;
        for(int i=1;i<chars.size();i++){
            if(chars[i-1]!=chars[i]){    
                chars[l]=chars[i-1];
                l++;
                if(c>1 && c<=9){
                    chars[l]=c+'0';
                    l++;
                }else if(c>=10){
                    string temp=to_string(c);
                    for(auto k:temp){
                        chars[l]=k;
                        l++;
                    }
                }
                c=1;
            }else{
                c++;
            }
        }
        chars[l]=chars.back();
        l++;
        if(c>1 && c<=9){
            chars[l]=c+'0';
            l++;
        }else if(c>=10){
            string temp=to_string(c);
            for(auto k:temp){
                chars[l]=k;
                l++;
            }
        }
        return l;
    }
};