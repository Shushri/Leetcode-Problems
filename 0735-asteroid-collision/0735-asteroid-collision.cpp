class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            int ele=ast[i];
            while(!st.empty() && ele<0 && st.top()>0 && abs(ele)>abs(st.top())){
                st.pop();
            }
            if(!st.empty() && ele<0 && st.top()>0 && abs(ele)==abs(st.top())){
                st.pop();
            }
            else if(!st.empty() && ele<0 && st.top()>0 && abs(ele)<abs(st.top())){

            }
            else{
                st.push(ele);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};