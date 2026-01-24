class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size();
        int ans=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        while(t[k]!=0){
            int ind=q.front();
            q.pop();
            t[ind]--;
            if(t[ind]>0){
                q.push(ind);
            }
            ans++;
        }
        return ans;
    }
};