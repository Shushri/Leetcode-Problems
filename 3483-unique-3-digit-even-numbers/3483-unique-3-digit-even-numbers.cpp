class Solution {
public:
    
    int totalNumbers(vector<int>& d) {
        unordered_set<string> st;
        int n=d.size();
        string s="";
        for(int i=0;i<n;i++){
            if(d[i]==0) continue;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    if(d[k]%2==1){
                        continue;
                    }
                
                    s+=(char)('0'+d[i]);
                    s+=(char)('0'+d[j]);
                    s+=(char)('0'+d[k]);
                    
                    st.insert(s);
                    s="";
                    
                }
            }
        }
        return st.size();
    }
};