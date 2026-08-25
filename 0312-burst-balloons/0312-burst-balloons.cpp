class Solution {
public:
    int f(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int sm=nums[ind]*nums[i-1]*nums[j+1]+f(i,ind-1,nums)+f(ind+1,j,nums);
            maxi=max(maxi,sm);
        }
        return maxi;

    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return f(1,n,nums);
       
    }
};