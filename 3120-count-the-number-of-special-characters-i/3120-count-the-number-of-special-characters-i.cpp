class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,pair<int,int>> mpp;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                char cc=word[i]-'A'+'a';
                mpp[cc].second=1;
            }
            else{
                mpp[word[i]].first=1;
            }
        }
        int ans=0;
        for(auto x:mpp){
            if(x.second.first==1 && x.second.second==1){
                ans++;
            }
        }
        return ans;
    }
};