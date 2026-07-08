class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        int p=1+m/n;
        string s="";
        for(int i=0;i<=p+1;i++){
            if(s.find(b)!=string::npos){
                return i;
            }
            s+=a;

        }
        return -1;

    }
};