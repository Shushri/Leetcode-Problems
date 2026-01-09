class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0;
        int one=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                one++;
                mx=max(mx,one);
            }
            else{
                one=0;
            }

        }
        return mx;

    }
};