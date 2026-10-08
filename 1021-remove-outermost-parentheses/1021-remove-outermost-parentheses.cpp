class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ss="";
        for (int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
            }
            else{
                c--;
            }
            if(c!=1 && c!=0){
                ss+=s[i];
            }
            else if(c==1 && s[i]==')'){
                ss+=s[i];
            }
            


        }
        return ss;
    }
};