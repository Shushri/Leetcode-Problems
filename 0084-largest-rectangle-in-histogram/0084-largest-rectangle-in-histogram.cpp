class Solution {
public:
    int largestRectangleArea(vector<int>& h ) {
         int n=h.size();
        int ans=0;
         stack<int> st;
         for(int i=0;i<=n;i++){
            int curr_h=i==n?0:h[i];
            while(!st.empty() && h[st.top()]>curr_h){
                
                int ht=h[st.top()];
                st.pop();
                int wd=st.empty()?i:i-st.top()-1;
                int ar=ht*wd;
                ans=max(ans,ar);cout<<ans<<endl;
                

            }
            st.push(i);
         }
      
         return ans;
    }
};