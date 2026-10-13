class Solution {
public:
    int f(int ind,string &s,int &n,vector<int> &dp){
        if(ind==n){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int r=f(ind+1,s,n,dp);;
        if((ind+1)<n && (s[ind]=='1' || (s[ind]=='2' &&  s[ind+1]<='6'))){
            r+=f(ind+2,s,n,dp);
        }  
        return dp[ind]=r;
    }
    int numDecodings(string s) {
        int n=s.size();
        
        vector<int> dp(n,-1);
        return f(0,s,n,dp);

    }
};