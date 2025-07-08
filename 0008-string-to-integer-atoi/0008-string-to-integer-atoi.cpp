class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0){
            return 0;
        }
        int i=0;
        while(s[i]==' ' && i<s.size()){
            i++;
        }
        s=s.substr(i);
        int sign=+1;
        if(s[0]=='-'){
            sign=-1;
        }
        if(s[0]=='-' || s[0]=='+'){
            i=1; //can't do i++ as value of i was changed earlier
        }
        else{
            i=0;
        }

        long ans=0;
        while(i<s.size() && isdigit(s[i])){
            
                ans=ans*10+(s[i]-'0');
                if(sign==-1 && -1*ans<INT_MIN){
                    return INT_MIN;
                }
                else if(sign==1 && ans>INT_MAX){
                    return INT_MAX;
                }
            
                i++;
        }
        return sign*ans;

    }
};