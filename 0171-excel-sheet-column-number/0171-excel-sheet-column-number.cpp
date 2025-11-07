class Solution {
public:
    int titleToNumber(string s) {
        int c=0;
        for(int i=s.size()-1;i>=0;i--){
            int p=s.size()-i-1;
            int cc=s[i]-'A'+1;
            
            int pwr=pow(26,p);
            c+=pwr*cc;
        }   
        return c;
    }
};