class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string ss="";
        for(int i=0;i<s.size();i++){
            ss="";
            while(i<s.size() && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) ){
                ss+=s[i];
                i++;
            }
            if(!ss.empty())
             ans.push_back(ss);
            ss="";
        }

        string anss="";
        for(int i=ans.size()-1;i>0;i--){
            string st=ans[i];
            
            anss+=st;
            anss+=' ';
        }
        anss+=ans[0];
        return anss;

    }
};