class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n=ast.size();
        for(int i=0;i<n;i++){
            if(ast[i]<0){
                int e=0;
                while(!st.empty() && ast[st.top()]>=0 && ast[st.top()]<=abs(ast[i])){
                    if(ast[st.top()]==abs(ast[i])){
                        e=1;
                        st.pop();
                        break;
                    }
                    st.pop();

                }
                if((st.empty() || (!st.empty() && ast[st.top()]<abs(ast[i])) ) && e==0){
                    st.push(i);
                }
                
                
            }
            else{
                st.push(i);    
            }
                
            
            
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(ast[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};