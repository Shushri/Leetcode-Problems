class Solution {
public:
    
    
    string addBinary(string a, string b) {
        string ans="";
        int n=a.length();
        int m=b.length();
        if (n > m) {
            for (int i = 0; i < n-m; i++) {
                b = '0' + b;
            }
        } else {
            for (int i = 0; i < m-n; i++) {
                a = '0' + a;
            }
        }
        int c=0;

        int sz=a.length();
        for (int i=sz-1;i>=0;i--){
            int sm=(a[i]-'0')+(b[i]-'0')+c;
            if(sm==0){
                ans+='0';
                c=0;
            }
            else if(sm==1){
                ans+='1';
                c=0;
            }
            else if(sm==2){
                ans+='0';
                c=1;
            }
            else if(sm==3){
                ans+='1';
                c=1;
            }
        }
        if(c==1){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};