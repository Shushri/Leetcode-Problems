class Solution {
public:
    bool f(int i,int j,int ind,vector<vector<int>> &vis,vector<vector<char>>& board,string &word,vector<int> &dc,vector<int> &dr){
        if(ind==word.size()){
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        for(int p=0;p<4;p++){
            int rw=i+dr[p];
            int cl=j+dc[p];
            if(rw>=0 && rw<n && cl>=0 && cl<m && vis[rw][cl]==0 && word[ind]==board[rw][cl]){
                if(f(rw,cl,ind+1,vis,board,word,dc,dr)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dc={-1,0,1,0};
        vector<int> dr={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    
                    if(f(i,j,1,vis,board,word,dc,dr)) return true;
                }
            }
        }
        return false;
    }
};