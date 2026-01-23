class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int bottom=st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int left=st.top();
                int wd=i-left-1;
                int ht=min(height[i],height[left])-height[bottom];
                ans+=wd*ht;
            }
            st.push(i);
        }
        return ans;
    }
};