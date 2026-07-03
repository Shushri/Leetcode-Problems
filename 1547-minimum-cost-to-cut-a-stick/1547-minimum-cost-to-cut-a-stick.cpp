class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+f(ind+1,j,cuts,dp)+f(i,ind-1,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return f(1,cuts.size()-2,cuts,dp);
    }
};