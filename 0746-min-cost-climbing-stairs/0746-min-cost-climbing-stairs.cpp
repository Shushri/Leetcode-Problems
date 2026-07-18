class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int pre1=cost[0];
        int pre2=cost[1];
        for(int ind=2;ind<cost.size();ind++){
            int temp=pre1;
            pre1=pre2;
            pre2=cost[ind]+min(temp,pre2);
        }
        return min(pre1,pre2);
    }
};