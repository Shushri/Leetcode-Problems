class Solution {
public:
    string convert(string s, int r) {
        int n=s.size();
        if(r==1 || n<=r){
            return s;
        }
        int cycle=2*r-2;
        string ans="";
        int p=0;
        int i=0;
        while(i<r){
            int j=i;
            ans+=s[i];
            while(true){
                j+=cycle;
                if((j-2*p)<n && p<=(r-2) && p>0){
                    ans+=s[j-2*p];

                }
                if(j<n){
                    ans+=s[j];
                }
                else{
                    break;
                }

            }
            p++;
            i++;
        }
        return ans;
    }
};