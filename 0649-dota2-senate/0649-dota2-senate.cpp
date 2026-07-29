class Solution {
public:
    string predictPartyVictory(string sen) {
        queue<int> R;
        queue<int> D;
        int n=sen.size();
        for(int i=0;i<n;i++){
            if(sen[i]=='R'){
                R.push(i);
            }
            else{
                D.push(i);
            }
        }
        int pos=n;
        while(!R.empty() && !D.empty()){
            if(R.front()>D.front()){
                R.pop();
                D.pop();
                D.push(pos++);

            }
            else{
                D.pop();
                R.pop();
                R.push(pos++);
            }
        }
        if(!R.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};