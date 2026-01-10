class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        int pos=0;
        stack<int> st;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            
                st.push(i);
                ans.push_back("Push");
                
            
            if(st.top()!=t[pos]){
                st.pop();
                ans.push_back("Pop");
                

            }
            else{
                pos++;
            }
            if(pos==t.size()){
                break;
            }

        }
        return ans;
    }
};