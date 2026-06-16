class Solution {
public:
    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(auto c='1';c<='9';c++){
                        if(isvalid(i,j,c,board)==true){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(int i,int j, char c,vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            //column traversal
            if(board[i][r]==c){
                return false;
            }
            //row traversal
            if(board[r][j]==c){
                return false;
            }
            //3X3 box traversal
            if( board[3*(i/3) + r/3][3*(j/3) + r%3]==c){
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};