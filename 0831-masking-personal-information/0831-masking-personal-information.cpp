class Solution {
public:
    string maskPII(string s) {
        size_t pos=s.find("@");
        string ans="";
        if(pos==string::npos){
            vector<char> pp;
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                    pp.push_back(s[i]);
                }
            }

            for(int i=0;i<4;i++){
                ans=pp[pp.size()-i-1]+ans;

            }
            ans="***-***-"+ans;
            if(pp.size()==11){
                ans="+*-"+ans;   
            }
            if(pp.size()==12){
                ans="+**-"+ans;   
            }
            if(pp.size()==13){
                ans="+***-"+ans;   
            }
        }
        else{
            ans+=tolower(s[0]);
            ans+="*****";
            int i=0;
            for(i;i<s.size();i++){
                if(s[i]=='@'){
                    break;
                }
            }
            
            ans+=tolower(s[i-1]);
            
            for(i;i<s.size();i++){
                ans+=tolower(s[i]);
            }


        }
        return ans;
    }
};