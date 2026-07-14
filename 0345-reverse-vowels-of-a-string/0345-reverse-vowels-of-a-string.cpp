class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int c=0;
        string vow="aeiouAEIOU";
        string vec="";
        for(int i=n-1;i>=0;i--){
            if(vow.find(s[i])!=string::npos){
                vec+=(s[i]);
            }
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(vow.find(s[i])!=string::npos){
                s[i]=vec[j++];
            }
        }
        return s;


    }
};