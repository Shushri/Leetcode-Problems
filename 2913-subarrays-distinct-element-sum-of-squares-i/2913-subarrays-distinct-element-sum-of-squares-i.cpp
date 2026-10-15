class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            int dis=0;
            for(int j=i;j<n;j++){
                if(mpp[nums[j]]==0){
                    dis++;
                }
                ans+=dis*dis;
                mpp[nums[j]]=1;
            }
        }
        return ans;
    }
};