class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        mpp['b']=0;
        mpp['a']=0;
        mpp['l']=0;
        mpp['o']=0;
        mpp['n']=0;
        int n=text.size();
        for(int i=0;i<n;i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n' ){
                mpp[text[i]]++;
            }
        }
        int ans=INT_MAX;
        for(auto ele:mpp){
            if(ele.first=='l' || ele.first=='o'){
                ans=min(ans,ele.second/2);
            }
            else{
                ans=min(ans,ele.second);
            }
        }
        return ans;
    }
};