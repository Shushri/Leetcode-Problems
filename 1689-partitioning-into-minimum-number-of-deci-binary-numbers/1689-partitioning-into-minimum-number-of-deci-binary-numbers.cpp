class Solution {
public:
    int minPartitions(string n) {
        int c=0;
        for(int i=0;i<n.size();i++){
            int nm=(int)(n[i]-'0');
            c=max(c,nm);
        }
        return c;
    }
};