class Solution {
public:
    double dfs(string u, string v, unordered_map<string, vector<pair<string,double>>> &g, unordered_set<string> &vis){
        if(u==v) return 1.0;

        vis.insert(u);

        for(auto &x : g[u]){
            if(!vis.count(x.first)){
                double t = dfs(x.first, v, g, vis);
                if(t != -1.0)
                    return x.second * t;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        unordered_map<string, vector<pair<string,double>>> g;

        for(int i=0;i<eq.size();i++){
            g[eq[i][0]].push_back({eq[i][1], val[i]});
            g[eq[i][1]].push_back({eq[i][0], 1.0/val[i]});
        }

        vector<double> ans;

        for(auto &x : q){
            string u = x[0];
            string v = x[1];

            if(!g.count(u) || !g.count(v)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(u, v, g, vis));
        }

        return ans;
    }
};