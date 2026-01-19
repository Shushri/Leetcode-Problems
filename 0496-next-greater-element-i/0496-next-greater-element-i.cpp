class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> mpp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && st.top()<nums2[i]){
                mpp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mpp[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mpp[nums1[i]];
        }
        return nums1;

    }
};