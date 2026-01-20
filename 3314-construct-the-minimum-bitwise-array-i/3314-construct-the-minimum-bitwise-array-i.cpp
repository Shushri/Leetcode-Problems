class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int b=0;
            for(int j=0;j<nums[i];j++){
                if((j | j+1)==nums[i]){
                    nums[i]=j;
                    b=1;
                    break;
                }
            }
            if(b==0){
                nums[i]=-1;
            }
        }
        return nums;
    }
};