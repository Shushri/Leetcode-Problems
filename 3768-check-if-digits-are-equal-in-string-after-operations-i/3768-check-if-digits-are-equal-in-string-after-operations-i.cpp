class Solution {
public:
    bool hasSameDigits(string s) {
        string p="";
        while(s.size()>2){
                
                for(int i=0;i<s.size()-1;i++){
                    int sm=s[i]-'0'+s[i+1]-'0';
                    sm=sm%10;
                    p+=to_string(sm);
                    
                }
                s=p;
                p="";
        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
        
    }
};