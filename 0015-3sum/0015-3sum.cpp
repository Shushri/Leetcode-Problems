class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> aaa;
        int n=nums.size();
        for (int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){int sss=nums[i]+nums[j]+nums[k];
            if(sss==0){
                aaa={nums[i],nums[j],nums[k]};
                ans.insert(aaa);
                j++;
                k--;
            }
            else if(sss>0){
                k--;
            }
            else{
                j++;
            }}

        }
        vector<vector<int>> anss(ans.begin(),ans.end());
        
        return anss;
    }
};