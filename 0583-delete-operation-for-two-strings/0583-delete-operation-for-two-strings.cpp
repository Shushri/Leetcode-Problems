class Solution {
public:
    int f(int i,int j,string &w1,string &w2,vector<vector<int>> &dp){
        //base case
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return dp[i][j]=1+f(i-1,j-1,w1,w2,dp);
        return dp[i][j]= 0+max(f(i-1,j,w1,w2,dp),f(i,j-1,w1,w2,dp));
    }
    int minDistance(string w1, string w2) {

        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int mx= f(n-1,m-1,w1,w2,dp);
        return n+m-2*mx;
    }
};