class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                mpp1[s[i]]++;
            }
            else{
                mpp2[s[i]]++;
            }
        }
        int mx=0;
        for(auto a:mpp1){
            mx=max(mx,a.second);
        }
        int mx2=0;
        for(auto a:mpp2){
            mx2=max(mx2,a.second);
        }
        return mx+mx2;

    }
};