class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int f=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                f=1;
                sort(nums.begin()+i,nums.end());
                int j=i;

                while(j<n){
                    if(nums[i-1]<nums[j]){
                        swap(nums[i-1],nums[j]);
                        break;
                    }
                    j++;
                }
            }
            if(f==1){
                break;
            }
        }
        if(f==0){
            sort(nums.begin(),nums.end());
            
        }
      
    }
};

//1 2 3 5 4 6 7