class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=-1;
        int b=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                a=nums[i];
            }
            if(nums[i]-nums[i-1]==2){
                b=nums[i]-1;
            }
        }
        if(b==-1){
            if(nums[0]==1){
                b=nums.size();
            }
            else{
                b=1;
            }
            
        }
        return {a,b};
    }
};