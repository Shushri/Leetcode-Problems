class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_set<int> st1;
        unordered_set<int> st2;
        for(int i=0;i<n1;i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])==nums2.end()){
                st1.insert(nums1[i]);
            }
        }
        for(int i=0;i<n2;i++){
            if(find(nums1.begin(),nums1.end(),nums2[i])==nums1.end()){
                st2.insert(nums2[i]);
            }
        }
        vector<vector<int>> ans(2);
        for(auto ele:st1){
            ans[0].push_back(ele);
        }
        for(auto ele:st2){
            ans[1].push_back(ele);
        }
        return ans;
    }
};