class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pre(gain.size()+1,0);
        for(int i=0;i<gain.size();i++){
            pre[i+1]=gain[i]+pre[i];
        }
        return *max_element(pre.begin(),pre.end());
    }
};