class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        //har letter ka first occ  
        vector<int> L(26,n);
        //ar letter ka last occ
        vector<int> R(26,-1);

        for (int i = 0; i < s.size(); i++) {
            L[s[i] - 'a'] = min(L[s[i] - 'a'], i);
            R[s[i] - 'a'] = i;
        }

        //fxn inside fxn which can use the local variables
        auto getRight = [&](int i) {
            int right = R[s[i] - 'a'];

            for (int j = i; j <= right; j++) {
                if (L[s[j] - 'a'] < i)
                    return -1;

                right = max(right, R[s[j] - 'a']);
            }
            return right;
        };

        vector<string> ans;
        int prevRight = -1;

        for (int i = 0; i < s.size(); i++) {
            if (i != L[s[i] - 'a'])   //hamesha first occurance se hi dekhna hai kyunki agr kisi aur se dekhenge to first occ miss ho jaayega and acc to ques aisa nhi krna hai
                continue;

            int right = getRight(i);  //fxn called from 1st occurance 

            if (right == -1)
                continue;

            if (i > prevRight) {
                ans.push_back(s.substr(i, right - i + 1));
            } else {
                ans.back() = s.substr(i, right - i + 1);  //arr ke end me jo string add hui thi ussee replace kr rhe hain kyunki wo overlap kr rha prev waale se.
            }

            prevRight = right;
        }

        return ans;
    }
};