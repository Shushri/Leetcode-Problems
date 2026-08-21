class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int>&dp){
	if(ind==nums.size()){
	return 0;
}
if(ind==nums.size()-1){
	return nums[ind];
}
if(dp[ind]!=-1) return dp[ind];
int take=nums[ind]+f(ind+2,nums,dp);
int ntake=0+f(ind+1,nums,dp);
return dp[ind]=max(take,ntake);
}
int rob(vector<int> &nums){
	int n=nums.size();
	vector<int> dp(n+1,-1);
	return f(0,nums,dp);
}

};