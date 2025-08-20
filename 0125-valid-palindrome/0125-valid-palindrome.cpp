class Solution {
public:
    bool cond(char c){
        if((c>='a' && c<='z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string st) {
        int n=st.size();
        int l=0;
        int h=n-1;
        while(l<=h){
             if(cond(tolower(st[l])) && cond(tolower(st[h]))){
                if(tolower(st[l])!=tolower(st[h])){
                    return false;
                }
                else{
                    l++;
                    h--;
                }
                
             }
             else if(!cond(tolower(st[l])) && !cond(tolower(st[h]))){
                l++;h--;
             }
             else if(!cond(tolower(st[l]))){
                l++;
             }
             else if(!cond(tolower(st[h]))){
                h--;
             }
             else{

             }

        }
        return true;
    }
};