class CustomStack {
public:
    stack<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(st.size()+1>maxSize){
            return;
        }
        st.push(x);
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int a=st.top();
        st.pop();
        return a;
    }
    void increment(int k, int val) {
       int n=st.size();
       if(n==-1){
        return;
       }
       vector<int> temp(n);
       for(int i=n-1;i>=0;i--){
        temp[i]=st.top();
        st.pop();
       }
       for(int i=0;i<min(k,n);i++){
        temp[i]+=val;
       }
       for(int i=0;i<n;i++){
        st.push(temp[i]);
       }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */