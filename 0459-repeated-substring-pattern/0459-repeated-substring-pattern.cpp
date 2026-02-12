class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            string subs=s.substr(0,i+1);
            int j=i+1;
            if(j==n){
                return false;
            }
            while(s.substr(j,i+1)==subs){
                j+=(i+1);
            }
            if(j==n){
                return true;
            }
        }   
        return false;
    }
};