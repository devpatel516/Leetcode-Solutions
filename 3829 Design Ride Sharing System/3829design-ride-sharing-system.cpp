class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(drivers.empty() || riders.empty()){
            return {-1,-1};
        }
        int a=drivers.front();
        drivers.pop();
        int b=riders.front();
        riders.pop();
        return {a,b};
    }
    
    void cancelRider(int riderId) {
        queue<int> q;
        while(!riders.empty()){
            if(riders.front()!=riderId){
                q.push(riders.front());
                riders.pop();
            }else{
                riders.pop();
            }
        }
        riders=q;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */