class Solution {
public:
    int numOfStrings(vector<string>& p, string w) {
        int n=p.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(w.find(p[i])!= string::npos){
                c++;
            }
        }
        return c;
    }

};