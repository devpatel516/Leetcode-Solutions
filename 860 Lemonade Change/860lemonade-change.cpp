class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;
        int twentys=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;
            }
            else if(bills[i]==10 && fives>=1){
                tens++;
                fives--;
            }else if(bills[i]==20 && fives>=1 && tens>=1){
                fives--;
                tens--;
                twentys++;
            }else if(bills[i]==20 && fives>=3){
                fives-=3;
                twentys++;
            }else{
                return false;
            }
        }
        return true;
    }
};