class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n){
            int r=n%26;
            n=n/26;
            if(r==0){
                r=26;
            }
            ans=(char)(65+r-1)+ans;
            if(r==26 && n==1){
                break;
            }
           
            
        }
        return ans;
    }
};
//1000
//1000-38x26=12
//38-26=12
//ALL
//701
//701/26=26
//n=26
//r=25  ans=Y
//26%26=0   ans=ZY
//