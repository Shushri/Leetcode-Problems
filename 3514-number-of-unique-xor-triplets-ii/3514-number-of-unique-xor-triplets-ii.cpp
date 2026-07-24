class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> xr;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int p=nums[i]^nums[j];
                xr.insert(p);
            }
        }
        unordered_set<int> ans;
        for(auto ele:xr){
            for(int i=0;i<n;i++){
                int ss=ele^nums[i];
                ans.insert(ss);
            }
        }
        return ans.size();
    }
};