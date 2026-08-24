class Solution {
public:
    int f(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        if(i==word1.size() ) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
         if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=0+f(i+1,j+1,word1,word2,dp);
        }
        int a=1+f(i,j+1,word1,word2,dp);
        int b=1+f(i+1,j,word1,word2,dp);
        int c=1+f(i+1,j+1,word1,word2,dp);
        return dp[i][j]=min(a,min(b,c));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(0,0,word1,word2,dp);

    }
};