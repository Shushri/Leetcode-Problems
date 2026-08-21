class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int curr=temp[i];
            while(!st.empty() && curr>temp[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};