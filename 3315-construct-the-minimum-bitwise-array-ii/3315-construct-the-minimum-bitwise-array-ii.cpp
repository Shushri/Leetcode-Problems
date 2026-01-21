class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]&1)){
                ans[i]=-1;
            }
            else{
                int n=nums[i];  //101
                int p=((~n) & (n+1))>>1; //10 | 110 = 110 
                ans[i]=(n&(~p));  
            }

        }
        return ans;
    }
};
//000
//1000
//110
//001
//111010111
//111011000
//000101000
//