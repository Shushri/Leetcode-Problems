class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]<'0' || board[i][j]>'9'){
                    continue;
                }
                char n=board[i][j];
                for(int k=0;k<9;k++){
                    if(k==j){
                        continue;
                    }
                    if(n==board[i][k]){
                        cout<<1<<" "<<n;
                        return false;
                    }
                }
                for(int k=0;k<9;k++){
                    if(k==i){
                        continue;
                    }
                    if(n==board[k][j]){
                        cout<<2<<" "<<n;
                        return false;
                    }
                }
                int p=i/3;
                int q=j/3;
                for(int k=p*3;k<p*3+3;k++){
                    for(int x=q*3;x<q*3+3;x++){
                        if(k==i && x==j){
                            continue;
                        }
                        if(n==board[k][x]){
                            cout<<3<<" "<<n;
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};