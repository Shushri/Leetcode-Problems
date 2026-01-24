class Solution {
public:
    int trap(vector<int>& h) {
        int ans=0;
        int n=h.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]<h[i]){
                int bottom=st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int left=st.top();
                int width=i-left-1;
                int height=min(h[left],h[i])-h[bottom];

                ans+=width*height;
            }
            st.push(i);
        }
        return ans;
    }
};