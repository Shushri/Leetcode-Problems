class Solution {
public:
    void makelps(string &s, vector<int> &lps){
        int len=0;
        int i=1;
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;

                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n,0);
        makelps(s,lps);
        return s.substr(0,lps[n-1]);

    }
};