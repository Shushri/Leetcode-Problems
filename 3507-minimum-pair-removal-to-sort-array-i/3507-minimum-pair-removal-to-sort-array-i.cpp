class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ind=0;
        int n=nums.size();
        int mnsm=INT_MAX;
        int c=0;
        while(true){
            ind=-1;
            mnsm=INT_MAX;
            int f=0;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    f=1;
                }

                if( nums[i]+nums[i+1]<mnsm){
                    mnsm=nums[i]+nums[i+1];
                    ind=i;
                }
            }
            if(f==0){
                return c;
            }
            else {
                nums.erase(nums.begin() + ind, nums.begin() + ind + 2);
                nums.insert(nums.begin() + ind, mnsm);
                c++;
            }


            
        }
        return -1;
        
    }
};