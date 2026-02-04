class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n=s.size();
        if(n<=1){
            return n;
        }
        int i=0;
        int j=0;
        int ans=0;
        
        while(j<n){
            if(mpp[s[j]]==0){
                
                mpp[s[j]]=1;
                j++;
            }
            else{
                mpp[s[i]]--;
                i++;

            }
            cout<<s[i]<<" "<<s[j]<<endl;
            ans=max(ans,j-i);
        }
        return ans;
    }
};