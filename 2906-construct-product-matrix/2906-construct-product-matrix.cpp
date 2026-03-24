class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        int total = n * m;
        vector<int> arr;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr.push_back(grid[i][j] % mod);
            }
        }

        vector<int> prefix(total, 1), suffix(total, 1);
        for(int i = 1; i < total; i++){
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }

        for(int i = total - 2; i >= 0; i--){
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }
      vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < total; i++){
            int val = (prefix[i] * suffix[i]) % mod;
            res[i / m][i % m] = val;
        }

        return res;
    }
};