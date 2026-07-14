class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int n=chars.size();
        int ch=chars[0];
        int c=1;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                c++;
            }
            else{
                if(c==1){
                    s+=chars[i-1];
                }
                else{
                    s+=chars[i-1];
                    s+=to_string(c);
                }
                c=1;
            }
        }
        if(c==1){
            s+=chars[n-1];
        }
        else{
                s+=chars[n-1];
                s+=to_string(c);
        }
        vector<char> ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(s[i]);
        }
        chars=ans;
        return s.size();
    }
};