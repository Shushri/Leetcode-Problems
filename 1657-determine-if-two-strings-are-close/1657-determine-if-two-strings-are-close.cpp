class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n!=m) return false;
        int freq1[26]={0};
        int freq2[26]={0};
        for(int i=0;i<n;i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if((freq1[i]!=0 && freq2[i]==0)||(freq1[i]==0 && freq2[i]!=0)) return false;
        }
        sort(freq1,freq1+26);
        sort(freq2,freq2+26);

        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
};