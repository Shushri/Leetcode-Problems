class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int i;
        int ones=0;
        for(int p=0;p<n;p++){
            if(s[p]=='1'){
                ones++;
            }
        }
        if(ones==0 || ones==n) return ones;
        int c10=0;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                break;
            }
        }
        while(s[i]=='0'){
            c10++;
            i++;
        }
        int mx=ones;

        while(i<n){
            int c11=0;
            while(i<n && s[i]=='1'){
                i++;
                c11++;
            }
            
            int c20=0;
            while(i<n && s[i]=='0'){
                i++;
                c20++;
            }
            if(c20==0) break;
            
            mx=max(mx,ones+c20+c10);
            c10=c20;
        }

        return mx;

    }
};