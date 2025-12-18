class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        int i=n1-1;
        int j=n2-1;
        int c=0;
        vector<int> ans(max(n1,n2)+1);
        int k=ans.size()-1;
        while(i>=0 && j>=0){
            int sm=(num1[i--]-'0')+(num2[j--]-'0')+c;
            ans[k--]=sm%10;
            c=sm/10;
        }
        while(i>=0 ){
            int sm=(num1[i--]-'0')+c;
            ans[k--]=sm%10;
            c=sm/10;
        }
        while( j>=0){
            int sm=(num2[j--]-'0')+c;
            ans[k--]=sm%10;
            c=sm/10;
        }
        ans[k]=c;
        string anss="";
        for(int i=ans.size()-1;i>=0;i--){
            if(i==0 && ans[i]==0){
                continue;
            }
            anss=(char)(ans[i]+'0')+anss;
        }
        return anss;


    }
};