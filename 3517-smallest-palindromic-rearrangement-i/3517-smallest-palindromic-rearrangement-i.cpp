class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        string h="";
        for(int i=0;i<n/2;i++){
            h.push_back(s[i]);
        }
        sort(h.begin(),h.end());
        
        string p=h;
        
        reverse(p.begin(),p.end());
       
        string ans="";
        if(n%2==0){
            ans=h+p;
        }
        else{
            
            ans=h+s[n/2]+p;
        }
        return ans;
    }
};