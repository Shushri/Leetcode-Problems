class Solution {
public:
    bool isPossible(vector<int>& t) {
        int n=t.size();
        
        long long sm=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sm+=t[i];
            pq.push(t[i]);
        }
        while(pq.top()!=1){
            int tp=pq.top();
            pq.pop();
            sm=sm-tp;
            if(sm>=tp || sm<=0){
                return false;
            }
            tp=tp%sm;
            sm+=tp;
            pq.push(tp>0?tp:sm);
        }
        return true;
        

    }
};