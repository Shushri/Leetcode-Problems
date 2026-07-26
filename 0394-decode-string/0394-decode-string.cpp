class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch != ']'){
                st.push(ch);
            }
            else{
                string sub="";
                while(!st.empty() && st.top()!='['){
                    sub += st.top();
                    st.pop();
                }
                reverse(sub.begin(), sub.end());

                st.pop(); // remove '['

                string nm="";
                while(!st.empty() && isdigit(st.top())){
                    nm += st.top();
                    st.pop();
                }
                reverse(nm.begin(), nm.end());

                int cnt = stoi(nm);

                string temp="";
                while(cnt--)
                    temp += sub;

                for(char c : temp)
                    st.push(c);
            }
        }

        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};