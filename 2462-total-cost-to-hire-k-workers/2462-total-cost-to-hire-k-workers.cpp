class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        int n=costs.size();
        int i=0,j=n-1;
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        pq1.push(INT_MAX);
        pq2.push(INT_MAX);
        for(int p=0;p<cand;p++){
            pq1.push(costs[i]);
            i++;
        }
        i--;
        for(int p=0;p<cand;p++){
            if(j==i){
                   
                break;
            }
            pq2.push(costs[j]);
            j--;
        }
        j++;
        long long ans=0;
        
        while(k--){
            if(pq1.top()<=pq2.top()){
                ans+=pq1.top();
              
                pq1.pop();
                
                
                if(i<(j-1)){
                    i++;
                    pq1.push(costs[i]);
                    pq1.top();
                    
                }
            }
            else{
                ans+=pq2.top();
               
                pq2.pop();
                if(i<(j-1)){
                    j--;
                    pq2.push(costs[j]);
                    
                }
            }
        }
        return ans;

    }
};