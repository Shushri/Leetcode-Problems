class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int ar=0;
        for(int i=0;i<=n;i++){
            int ht=((i==n)?0:heights[i]);
            while(!st.empty() && ht<heights[st.top()]){
                int hi=st.top();
                st.pop();
                
                int wd=st.empty()?i:i-st.top()-1;
                ar=max(ar,wd*heights[hi]);

            }
            st.push(i);
        }
        return ar;
    }
};