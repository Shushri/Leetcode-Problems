class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        string snew="";
        for (int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                st1.push(s[i]);
            }
            else if(st1.empty() && s[i]>='a' && s[i]<='z'){
                snew=s[i]+snew;
            }
            else if(st1.top()=='#'){
                st1.pop();
                continue;
            }
        }
        stack<char> st2;
        string tnew="";
        for (int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                st2.push(t[i]);
            }
            else if(st2.empty() && t[i]>='a' && t[i]<='z'){
                tnew=t[i]+tnew;
            }
            else if(st2.top()=='#'){
                st2.pop();
                continue;
            }
        }
        if(snew==tnew){
            return true;
        }
        return false;
    }
};