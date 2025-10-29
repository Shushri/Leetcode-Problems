class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        unordered_map<char,int> mpp;
        int mx=0;
        while(j<n){
            if(mpp[s[j]]==1){
                while(s[i]!=s[j]){
                    mpp[s[i]]=0;
                    i++;
                }
                mpp[s[i]]=0;
                i++;
                
            }
            int c=j-i+1;
            mx=max(mx,c);
            mpp[s[j]]=1;
            j++;
            
        }
        return mx;
    }
};