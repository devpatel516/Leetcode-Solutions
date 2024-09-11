class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int total=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                total-=s.top();
                s.pop();
            }
            else if(operations[i]=="D"){
                int doublevalue=2*s.top();
                s.push(doublevalue);
                total+=s.top();
            }
            else if(operations[i]=="+"){
                int one=s.top();
                s.pop();
                int two=s.top();
                s.push(one);
                int sum=one+two;
                s.push(sum);
                total+=sum;
            }
            else{
                s.push(stoi(operations[i]));
                total+=stoi(operations[i]);
            }
        }
        return total;
    }
};