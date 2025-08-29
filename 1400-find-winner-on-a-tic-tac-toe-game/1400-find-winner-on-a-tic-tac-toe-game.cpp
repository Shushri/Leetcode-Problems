class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3,vector<int>(3));
        int n=moves.size();
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                board[moves[i][0]][moves[i][1]]='X';
            }
            else{
                board[moves[i][0]][moves[i][1]]='O';
            }
        }
        for (int i=0;i<3;i++){
            if(board[i][0] && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                if(board[i][0]=='X'){
                    return "A";
                }
                else{
                    return "B";
                }
            }
            else if(board[0][i] && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
                if(board[0][i]=='X'){
                    return "A";
                }
                else{
                    return "B";
                }
            }
        }
        //diagonals
        if(board[0][0] && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            if(board[0][0]=='X'){
                return "A";
            }
            else{
                return "B";
            }
        }
        if(board[0][2] && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            if(board[0][2]=='X'){
                return "A";
            }
            else{
                return "B";
            }
        }

        if(moves.size()==9){
            return "Draw";
        }
        else{
            return "Pending";
        }

    }

};