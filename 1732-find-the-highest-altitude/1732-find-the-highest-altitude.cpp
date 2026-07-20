class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pre(gain.size()+1,0);
        int mx=0;
        for(int i=0;i<gain.size();i++){
            pre[i+1]=gain[i]+pre[i];
            mx=max(mx,pre[i+1]);
        }
        return mx;
    }
};