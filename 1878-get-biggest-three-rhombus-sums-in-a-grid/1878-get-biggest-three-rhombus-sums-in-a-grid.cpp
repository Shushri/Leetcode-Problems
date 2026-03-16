class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size();
        set<int> s;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                s.insert(g[i][j]);

                for(int k=1;;k++){
                    int nr = i + 2*k;
                    int l = j - k;
                    int rr = j + k;

                    if(nr>=r || l<0 || rr>=c) break;

                    int sm = 0;

                    for(int t=0;t<k;t++) sm += g[i+t][j+t];
                    for(int t=0;t<k;t++) sm += g[i+k+t][j+k-t];
                    for(int t=0;t<k;t++) sm += g[i+2*k-t][j-t];
                    for(int t=0;t<k;t++) sm += g[i+k-t][j-k+t];

                    s.insert(sm);
                }
            }
        }

        vector<int> a;
        for(auto it=s.rbegin(); it!=s.rend() && a.size()<3; it++){
            a.push_back(*it);
        }

        return a;
    }
};