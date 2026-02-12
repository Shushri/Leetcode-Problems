class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int cnt=mpp[s[i]];
                int f=0;
                for(auto ele:mpp){
                    if(ele.second!=cnt){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    ans=max(ans,j-i+1);
                }
            }

        }
        return ans;
    }
};