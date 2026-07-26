class RecentCounter {
public:
    
    vector<int > arr;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        arr.push_back(t);
        int i;
        for( i=0;i<arr.size();i++){
            if(t-arr[i]<=3000){
                break;
            }
        }
        return arr.size()-i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */