class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        stack<int> st;        
        int n=p.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && p[i]<=p[st.top()]){
                p[st.top()]=p[st.top()]-p[i];
                st.pop();
            }
            st.push(i);
        }
        return p;
    }
};


