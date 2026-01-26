class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1){
            return stones[0];
        }
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int tp1;
            int tp2;
            if(!pq.empty()){
                tp1=pq.top();
                pq.pop();
            }
            else{
                return 0;
            }
            if(!pq.empty()){
                tp2=pq.top();
                pq.pop();
            }
            else{
                return tp1;
            }
            if(tp1!=tp2){
                int dfff=abs(tp1-tp2);
                pq.push(dfff);
            }


            

        }
        return 0;
    }
};