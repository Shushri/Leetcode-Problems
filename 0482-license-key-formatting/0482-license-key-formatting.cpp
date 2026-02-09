class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n=s.size();
        vector<char> v;
        for(int i=0;i<n;i++){
            if(s[i]!='-'){
                v.push_back(toupper(s[i]));
            }
        }
        string ans="";
        if(v.size()<=k){
            for(int i=0;i<v.size();i++){
                ans+=v[i];
            }
            return ans;
        }

        int rem=v.size()%k==0?k:v.size()%k;
        
        int i=0;
        for(i;i<rem;i++){
            ans+=v[i];
        }
        
        ans+='-';
        
        for(i;i<v.size();i+=k){
            for(int j=0;j<k;j++){
                ans+=v[i+j];
            }
            if(i+k<=v.size()-1){
                ans+='-';
            }
            
        }
        return ans;
        

    }
};