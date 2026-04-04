class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> vcc(mpp.begin(),mpp.end());
        sort(vcc.begin(),vcc.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vcc[i].first);
        }
        return ans;

    }
};