class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int a=n/8;
        int b=n%8;
        int cnt=1;
        int ans=0;
        while(a--){
            ans+=8*cnt;
            cnt++;
        }
        ans+=cnt*b;
        return ans;
    }
};