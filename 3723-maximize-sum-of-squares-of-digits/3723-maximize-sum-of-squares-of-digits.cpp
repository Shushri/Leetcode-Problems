class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum){
            return "";
        }
        string ans="";
        for(int i=9;i>=1;i--){
            int x=sum/i;
            if(x!=0){
                for(int j=0;j<x;j++){
                    ans+=(i+'0');
                }
            }
            sum=sum-x*i;
        }
        if(ans.size()<num){
            int diff=num-ans.size();
            while(diff--){
                ans+='0';
            }
        }
        return ans;
        
    }
};

