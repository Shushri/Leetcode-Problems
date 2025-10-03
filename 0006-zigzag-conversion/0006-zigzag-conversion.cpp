class Solution {
public:
    string convert(string s, int r) {
        int n = s.size();
        if(r == 1 || r >= n) return s;

        // calculate columns
        int col = 0;
        int z = (r >= 3 ? r - 2 : 0);
        int temp = n;
        while(temp > 0){
            if(temp >= r){
                temp -= r;
                col++;
            } else{
                col++;
                temp = 0;
                break;
            }
            if(temp >= z){
                temp -= z;
                col += z;
            } else{
                col += temp;
                temp = 0;
                break;
            }
        }

        // create 2D grid
        vector<vector<char>> arr(r, vector<char>(col, ' '));

        int i = 0, c1 = 0;
        while(i < n){
            // vertical down
            int r1 = 0;
            while(r1 < r && i < n){
                arr[r1][c1] = s[i++];
                r1++;
            }

            // diagonal up
            r1 = r - 2;
            while(r1 > 0 && i < n){
                c1++;
                arr[r1][c1] = s[i++];
                r1--;
            }
            c1++;
        }

        // read row by row
        string ans = "";
        int row = 0;
        while(row < r){
            int cc = 0;
            while(cc < col){
                if(arr[row][cc] != ' '){
                    ans += arr[row][cc];
                }
                cc++;
            }
            row++;
        }

        return ans;
    }
};
