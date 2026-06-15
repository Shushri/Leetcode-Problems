class Solution {
public:
    bool isvalid(int row,int col,vector<string> &board){
        int n=board.size();
        int r=row;
        int c=col;
        //upper left diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=r;
        col=c;
        //left
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            
            col--;
        }
        col=c;
        //lower left diagonal
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;

    }
    bool rec(int col,int n,vector<string> &board,vector<vector<string>> & ans){
        if(col==n){
            ans.push_back(board);
            return true;
        }

        for(int row=0;row<n;row++){
            if(isvalid(row,col,board)==true){
                board[row][col]='Q';
                rec(col+1,n,board,ans);
                board[row][col]='.';

            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        rec(0,n,board,ans);
        return ans; 
    }
};