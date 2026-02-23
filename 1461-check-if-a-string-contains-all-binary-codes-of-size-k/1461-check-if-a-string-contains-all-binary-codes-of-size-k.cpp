class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n=s.size();
        for(int i=0;i<=n-k;i++){
            string ss=s.substr(i,k);
            st.insert(ss);
        }   
        if(st.size()==pow(2,k)){
            return true;
        }
        return false;
    }
};