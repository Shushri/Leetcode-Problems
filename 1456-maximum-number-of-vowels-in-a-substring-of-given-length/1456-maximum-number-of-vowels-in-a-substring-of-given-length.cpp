class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        vector<int> pref(n,0);
        string vow="aeiou";
        if(vow.find(s[0])!=string::npos){
            pref[0]=1;
        }
        for(int i=1;i<n;i++){
            if(vow.find(s[i])!=string::npos){
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