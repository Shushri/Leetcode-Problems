class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        vector<int> cnt;
        int ans=0;
        int o=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                o++;
                if(z){
                    cnt.push_back(z);
                    z=0;
                }
            }
            else{
                z++;
                if(o){
                    cnt.push_back(o);
                    o=0;
                }
            }
        }
        if(z){
            cnt.push_back(z);
        }
        if(o){
            cnt.push_back(o);
        }
        for(int i=1;i<cnt.size();i++){
            ans+=min(cnt[i],cnt[i-1]);
        }
        return ans;
    }
};