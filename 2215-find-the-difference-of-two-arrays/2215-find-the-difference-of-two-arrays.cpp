class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n1;i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mp2[nums2[i]]++;
        }
        vector<vector<int>> ans(2);
        for(auto ele:mp1){
            if(mp2[ele.first]==0){
                ans[0].push_back(ele.first);
            }
        }
        for(auto ele:mp2){
            if(mp1[ele.first]==0){
                ans[1].push_back(ele.first);
            }
        }
        return ans;
    }
};