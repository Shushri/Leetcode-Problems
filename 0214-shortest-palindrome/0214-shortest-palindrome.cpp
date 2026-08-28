class Solution {
public:
    void makelps(string &s,vector<int>& lps){
        int len=0;
        int i=1;
        int n=s.size();
        while(i<n){
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
    string shortestPalindrome(string s) {
        //using lps
        int n=s.size();
        string rev=s;reverse(rev.begin(),rev.end());
        string x=s+'$'+rev ;
        vector<int> lps(x.size(),0);
        makelps(x,lps);
        int longestLPSlength=lps[x.size()-1];
        string ans=rev.substr(0,n-longestLPSlength);
        ans=ans+s;
        return ans;
    }
};

//codewithmik
//abcd
//dcba
