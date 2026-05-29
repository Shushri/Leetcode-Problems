class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int d=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int p=0;p<4;p++){
                int rw=i+dr[p];
                int cl=j+dc[p];
                if(rw>=0 && rw<n && cl>=0 && cl<m ){
                    int df=abs(h[i][j]-h[rw][cl]);
                    if(dis[rw][cl]>max(d,df)){
                        dis[rw][cl]=max(d,df);
                        pq.push({max(d,df),{rw,cl}});
                    }
                }
            }

        }
        return dis[n-1][m-1];
    }
};