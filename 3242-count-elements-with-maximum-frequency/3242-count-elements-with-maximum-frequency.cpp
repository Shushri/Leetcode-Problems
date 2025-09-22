class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int ,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int mx=0;
        int c=0;
        for(auto ele:mpp){
            if(ele.second>mx){
                mx=ele.second;
                c=1;
            }
            else if(ele.second==mx){
                c++;
            }

        }
        
        return c*mx;
    }
};