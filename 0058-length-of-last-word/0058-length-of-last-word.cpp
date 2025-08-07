class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int c = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i]!= ' ') {
                break;
            }
            c++;
            
        }
        int count=0;
        for (int i = s.length()-1-c; i >= 0; i--) {
            if (s[i]== ' ' ) {
                break;
            }
            count++;
            
        }
        return count;
    }
};