class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ttlg=0;
        int ttlc=0;
        for(int i=0;i<n;i++){
            ttlg+=gas[i];
            ttlc+=cost[i];
        }
        if(ttlg<ttlc){
            return -1;
        }
        int ans=0;
        int ff=0;
        for(int i=0;i<n;i++){
            ff+=(gas[i]-cost[i]);
            if(ff<0){
                ff=0;
                ans=i+1;
            }

        }
        return ans;
    }
};