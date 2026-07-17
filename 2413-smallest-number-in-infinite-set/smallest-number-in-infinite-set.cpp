class SmallestInfiniteSet {
public:
    set<int> s;
    int c;
    SmallestInfiniteSet() {
        this->c=1;
    }
    
    int popSmallest() {
        if(!s.empty()){
            int a=*s.begin();
            s.erase(a);
            return a;
        }
        int temp=c;
        c++;
        return temp;
    }   
    
    void addBack(int num) {
        if(num<c){
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */