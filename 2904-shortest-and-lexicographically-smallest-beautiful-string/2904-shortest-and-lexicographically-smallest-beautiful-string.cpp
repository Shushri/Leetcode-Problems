class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        s+='0';
        int i=0;
        int j=0;
        int one=0;
        int ans=INT_MAX;
        int ind=-1;
        vector<string> lex;
        while(j<=n){            
            if(one==k){
                while(s[i]!='1'){
                    i++;
                }
                if(j-i<ans){
                    ans=j-i;
                    ind=i;
                }
                else if(j-i==ans){
                    if(s.substr(i,ans)<s.substr(ind,ans)){
                        ind=i;
                    }
                }
                one--;
                i++;
                
                
            }
            if(s[j]=='1'){
                one++;
                j++;
            }
            else{
                j++;
            }
            
        }      
        string ss="";
        if(ind==-1) return "";
        for(int i=ind;i<ind+ans;i++){
            ss+=s[i];
        }
        return ss;
    }
};

//100011001
//i=0, j=0
//one=1
//i=0, j=5
//one 3
//i=1, j=5, one = 2
//i=1,j=8, one 3
//