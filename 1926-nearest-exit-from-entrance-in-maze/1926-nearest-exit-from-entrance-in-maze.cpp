class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n=maze.size();
        int m=maze[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{ent[0],ent[1]},0});
        maze[ent[0]][ent[1]]='$';
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first.first;
                int y=q.front().first.second;
                int h=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int rw=x+dr[j];
                    int cl=y+dc[j];
                    if(rw>=0 && rw<n && cl>=0 && cl<m && maze[rw][cl]=='.' ){
                        maze[rw][cl]='$';
                        q.push({{rw,cl},h+1});
                        if(rw==0 || rw==n-1 || cl==0 || cl==m-1){
                            return h+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};