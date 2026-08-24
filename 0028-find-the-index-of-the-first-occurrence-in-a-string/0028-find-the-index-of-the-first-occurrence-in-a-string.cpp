class Solution {
public:
    void calculateLPS(string& pat,vector<int> & lps,int &m){
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string text, string pat) {
        int n=text.size();
        int m=pat.size();
        if(text==pat) return 0;

        vector<int> lps(m,0);
        calculateLPS(pat,lps,m);
        //kmp
        int i=0;
        int j=0;
        while(i<n){
            
            if(text[i]==pat[j]){
                i++;
                j++;
                if(j==m){
                return i-m;
            }
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }

        }
        return -1;
    }
};