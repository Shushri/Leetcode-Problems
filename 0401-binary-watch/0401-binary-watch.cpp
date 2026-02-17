class Solution {
public:
    
    int countBits(int x){
        return __builtin_popcount(x);
    }
    
    vector<string> readBinaryWatch(int t) {
        
        vector<string> ans;
        
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                
                if(countBits(h) + countBits(m) == t){
                    
                    string time = to_string(h) + ":";
                    
                    if(m < 10)
                        time += "0";   
                    
                    time += to_string(m);
                    
                    ans.push_back(time);
                }
            }
        }
        
        return ans;
    }
};
