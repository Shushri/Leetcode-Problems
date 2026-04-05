class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0;
        int v=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                h=h-1;
            }
            else if(moves[i]=='R'){
                h=h+1;
            }
            else if(moves[i]=='U'){
                v=v+1;
            }
            else{
                v=v-1;
            }
        }
        if(h==0 && v==0){
            return true;
        }
        return false;
    }
};