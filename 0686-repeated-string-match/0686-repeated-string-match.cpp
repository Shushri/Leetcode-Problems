class Solution {
public:
    vector<int> lps(string &p) {
        int m = p.size();
        vector<int> l(m);

        int len = 0;
        int i = 1;

        while(i < m) {
            if(p[i] == p[len]) {
                l[i] = ++len;
                i++;
            }
            else if(len != 0) {
                len = l[len - 1];
            }
            else {
                i++;
            }
        }

        return l;
    }

    bool kmp(string &s, string &p) {
        int n = s.size();
        int m = p.size();

        vector<int> l = lps(p);

        int i = 0, j = 0;

        while(i < n) {
            if(s[i] == p[j]) {
                i++;
                j++;

                if(j == m)
                    return true;
            }
            else if(j != 0) {
                j = l[j - 1];
            }
            else {
                i++;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        int k = (b.size() + a.size() - 1) / a.size();

        string s;

        for(int i = 0; i < k; i++)
            s += a;

        if(kmp(s, b))
            return k;

        s += a;

        if(kmp(s, b))
            return k + 1;

        return -1;
    }
};