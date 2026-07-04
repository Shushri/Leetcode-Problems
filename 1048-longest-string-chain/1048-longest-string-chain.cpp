class Solution {
public:
    bool check(string a,string b){
        if(b.size()!=a.size()+1){
            return false;
        }
        int i=0;
        int j=0;

        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        if(i==a.size() ){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return s1.size()<s2.size();
        });
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};