class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int vw=0;
        
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
            vw=1;
        }
        for(int i=1;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vw++;
            }
            
        }
        int j=0;
        int mx=vw;
        for(int i=k;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vw++;
            }
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                vw--;
            }
            j++;
            mx=max(mx,vw);
        }
        return mx;
    }
};