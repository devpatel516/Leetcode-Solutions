class FreqStack {
public:
    stack<int> s;
    priority_queue<tuple<int,int,int>> q;
    unordered_map<int,int> m;
    int sequence=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        q.push({m[val],sequence++,val});
    }
    
    int pop() {
        auto [f,s,v]=q.top();
        q.pop();
        m[v]--;
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */