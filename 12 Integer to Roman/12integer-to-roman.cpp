class Solution {
public:
    string intToRoman(int num) {
        int i=0;
        string str;
        int d[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        while(num>0){
            if(num>=d[i]){
                str=str+s[i];
                num=num-d[i];
            }else{
                i++;
            }
        }
        return str;
    }
};