class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ttlg=0;

        int ans=0;
        int ff=0;
        for(int i=0;i<n;i++){
            ff+=(gas[i]-cost[i]);
            ttlg+=(gas[i]-cost[i]);
            if(ff<0){
                ff=0;
                ans=i+1;
            }

        }
        if (ttlg<0){
            return -1;
        }
        return ans;
    }
};