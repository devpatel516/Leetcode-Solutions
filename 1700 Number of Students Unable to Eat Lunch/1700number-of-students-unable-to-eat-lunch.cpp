class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> d(students.begin(),students.end());
        stack<int> s;
        for(int i=sandwiches.size()-1;i>=0;i--){
            s.push(sandwiches[i]);
        }
        int c=0;
        while(!s.empty() && c<s.size()){
            if(d.front()==s.top()){
                s.pop();
                d.pop_front();
                c=0;
            }
            else{
                d.push_back(d.front());
                d.pop_front();
            c++;
            }
        }
        return s.size();
    }
};