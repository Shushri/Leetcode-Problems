class Solution {
public:
    string sortVowels(string s) {
        vector <char> vwl;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vwl.push_back(s[i]);
            }
        }
        sort(vwl.begin(),vwl.end());
        int pos=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                s[i]=vwl[pos++];
            }
        }
        return s;
    }
};