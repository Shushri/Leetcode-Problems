class Solution {
public:
    void f(vector<string> &ans, string& s,int o,int c){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o>c){
            return;
        }
        if(o>0){
            s+='(';
            f(ans,s,o-1,c);
            s.pop_back();
        }
        if(c>0){
            s+=')';
            f(ans,s,o,c-1);
            s.pop_back();
            

        }

    }
    vector<string> generateParenthesis(int n) {
        int o=n;
        int c=n;
        vector<string> ans;
        string s="";
        f(ans,s,o,c);
        return ans;
    }
};