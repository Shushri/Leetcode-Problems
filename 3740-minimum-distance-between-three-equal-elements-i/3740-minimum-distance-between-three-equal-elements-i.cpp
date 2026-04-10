class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,vector<int>>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].first++;
            mpp[nums[i]].second.push_back(i);
        }
        int ans=INT_MAX;
        int f=0;
        for(auto ele:mpp){
            if(ele.second.first>=3){
                f=1;
                vector<int> ind=ele.second.second;
                for(int i=2;i<ind.size();i++){
                    int ss=2*(ind[i]-ind[i-2]);
                    ans=min(ans,ss);
                }
            }
        }
        if(f==0)return -1;
        return ans;
    }
};