class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && (i-1==-1 || s[i-1]=='0')){
                c++;
            }
        }
        if(c>1){
            return false;
        }
        return true;
    }
};