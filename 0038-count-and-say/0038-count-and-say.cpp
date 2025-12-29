class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        string s="";
        for(int i=1;i<n;i++){
            int c=1;
            s="";
            if(ans.size()==1){
                ans="11";
                continue;
            }
            for(int j=1;j<ans.size();j++){
                if(ans[j]==ans[j-1]){
                    c++;
                }
                else{
                    s=s+(char)('0'+c)+ans[j-1];
                    c=1;
                }
            }
            s=s+(char)('0'+c)+ans[ans.size()-1];
            ans=s;

        }
        return ans;
    }
};