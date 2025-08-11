class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char> st;
        for (int i=s.size()-1;i>=0;i--){
            if(s[i]>='0' && s[i]<='9'){
                st.push(s[i]);
            }
            else if(!st.empty() ){
                st.pop();
            }
            else{
                ans+=s[i];
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};