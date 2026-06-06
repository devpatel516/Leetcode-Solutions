class MyHashMap {
public:
    vector<int> myMap;
    MyHashMap() {
        myMap=vector<int>(10000001,-1);
    }
    
    void put(int key, int value) {
        myMap[key+1]=value;
    }
    
    int get(int key) {
        return myMap[key+1];
    }
    
    void remove(int key) {
        myMap[key+1]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */