class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector <int> ans;
        int f1=0;
        for (int i=0;i<n;i++){
            if(nums[i]==target){
                ans.push_back(i);
                f1=1;
                break;
            }
        }
        if(f1==0){
            return {-1,-1};
        }
        for (int i=n-1;i>=0;i--){
            if(nums[i]==target){
                ans.push_back(i);
                f1=1;
                break;
            }
        }

    return ans;
    }
};