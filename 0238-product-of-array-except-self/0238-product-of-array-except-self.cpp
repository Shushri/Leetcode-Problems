class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long p=1;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
            }
            else{
                p*=nums[i];
            }
            
        }
        for(int i=0;i<nums.size();i++){
            if(c==0){
                nums[i]=p/nums[i];
            }
            else if(c==1){
                if(nums[i]==0){
                    nums[i]=p;
                }
                else{
                    nums[i]=0;
                }
            }
            else{
                nums[i]=0;
            }
        }
        return nums;
    }
};