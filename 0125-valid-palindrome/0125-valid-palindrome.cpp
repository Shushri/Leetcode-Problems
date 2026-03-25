class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        for(int i=0;i<s.size();i++){
            if(tolower(s[i])>='a' && tolower(s[i])<='z'){
                ss+=tolower(s[i]);
            }
        }
        int n=ss.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            if(ss[l]!=ss[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
};