class Solution {
public:
    bool check(string t,string s){
        if(s.find(t)==string::npos){
            return false;
        }
        if(s.size()%t.size()!=0){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i%t.size()]){
                return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(n<m){
            swap(str1,str2);
            swap(n,m);
        }
        
        string ans="";
        string t="";
        for(int i=0;i<m;i++){

            t+=str2[i];
            if(m%(i+1)==0){
                if(check(t,str2) && check(t,str1)){
                    ans=t;
                }
            }
        }
        return ans;
    }
};