class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s="1";
        for(int i=1;i<n;i++){
            int c=1;
            string p="";
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1]){
                    c++;
                }
                else{
                    p+=('0'+c);
                    p+=s[j-1];
                    c=1;
                }
            }
            p+=('0'+c);
            p+=s[s.size()-1];
            s=p;
        }
        return s;
    }
};