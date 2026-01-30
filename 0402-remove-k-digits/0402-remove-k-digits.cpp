class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        
        if(n==k){
            return "0";
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;
                
            }
            st.push(num[i]);
        }

        while(k){
            st.pop();
            k--;
        }
        
        string ans="";
        stack<char> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty() && st2.top()=='0'){
            st2.pop();
        }
        while(!st2.empty()){
            ans+=st2.top();
            st2.pop();
        }
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};