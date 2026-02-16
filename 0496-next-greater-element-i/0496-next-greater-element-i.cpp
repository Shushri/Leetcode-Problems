class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> st;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                mpp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            mpp[nums2[st.top()]]=-1;
            st.pop();
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};