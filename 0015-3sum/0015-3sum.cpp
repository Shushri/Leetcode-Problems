class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> aaa;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){int sss=nums[i]+nums[j]+nums[k];
            if(sss==0){
                aaa={nums[i],nums[j],nums[k]};
                ans.push_back(aaa);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
            else if(sss>0){
                k--;
            }
            else{
                j++;
            }}

        }
        
        
        return ans;
    }
};
