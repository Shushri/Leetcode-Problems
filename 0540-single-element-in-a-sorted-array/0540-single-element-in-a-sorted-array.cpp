class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map <int ,int > mpp;
        int ans=0;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for (auto a:mpp){
            if(a.second==1){
                ans=a.first;
            }
        }
        return ans;
    }
};