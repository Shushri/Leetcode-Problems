class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        vector<int> pref(n,0);
        
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u'){
            pref[0]=1;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                pref[i]=pref[i-1]+1;
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        int j=0;
        int mx=pref[k-1];
        for(int i=k;i<n;i++){
            int cnt=pref[i]-pref[j];
            j++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};