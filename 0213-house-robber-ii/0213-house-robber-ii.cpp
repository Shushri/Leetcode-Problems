class Solution {
public:
    int f1(int ind,vector<int>& nums,int n,vector<int>&dp1){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp1[ind]!=-1) return dp1[ind];

        int pick=nums[ind]+f1(ind-2,nums,n,dp1);
        int npick=0+f1(ind-1,nums,n,dp1);

        return dp1[ind]= max(pick,npick);
    }
    int f2(int ind,vector<int>& nums,int n,vector<int>&dp2){
        if(ind==1){
            return nums[ind];
        }
        if(ind<1){
            return 0;
        }
        if(dp2[ind]!=-1) return dp2[ind];

        int pick=nums[ind]+f2(ind-2,nums,n,dp2);
        int npick=0+f2(ind-1,nums,n,dp2);

        return dp2[ind]= max(pick,npick);
    }
    int rob(vector<int>& nums) {
        //this is a recurrence subsesquence problem with one extra constraint that the elements cant be take adjacent
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp1(nums.size(),-1);
        int l= f1(nums.size()-2,nums,nums.size(),dp1);
        vector<int> dp2(nums.size(),-1);
        int r= f2(nums.size()-1,nums,nums.size(),dp2);
        return max(l,r);
    }
};