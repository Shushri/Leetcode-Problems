class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        int ans=0;
        for (auto chr:st){
            int i=0;
            int j=0;
            int z=0;
            while(j<n){
                if(s[j]==chr){
                    j++;
                }
                else{
                    if(z==k){
                        if(s[i]!=chr){
                            z--;
                        }
                        
                        i++;
                    }
                    else{
                        z++;
                        j++;
                    }

                    
                }
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};