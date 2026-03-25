class Solution {
public:
    int longestConsecutive(vector<int>& stt) {
        if(stt.size()==0){
            return 0;
        }
        sort(stt.begin(),stt.end());
        int mx=1;
        int c=1;
        for(int i=1;i<stt.size();i++){
            if((long long)stt[i]-(long long)stt[i-1]==1){
                c++;
            }
            else if((long long)stt[i]-(long long)stt[i-1]>1){
                mx=max(mx,c);
                c=1;
            }
        }
        mx=max(mx,c);
        return mx;
    }
};