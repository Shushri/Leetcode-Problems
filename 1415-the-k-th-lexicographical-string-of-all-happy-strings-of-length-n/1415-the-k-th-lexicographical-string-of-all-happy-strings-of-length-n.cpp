class Solution {
public:
    string getHappyString(int length, int kth) {
        
        int blockSize = pow(2, length - 1);
        if (3 * blockSize < kth) return "";

        string result = "";

        if (kth <= blockSize) {
            result += 'a';
        } 
        else if (kth <= 2 * blockSize) {
            result += 'b';
            kth -= blockSize;
        } 
        else {
            result += 'c';
            kth -= 2 * blockSize;
        }

        vector<string> nextChars = {"bc", "ac", "ab"};

        for (int pos = 1; pos < length; pos++) {

            blockSize /= 2;
            string choices = nextChars[result.back() - 'a'];

            if (kth > blockSize) {
                result += choices[1];
                kth -= blockSize;
            } 
            else {
                result += choices[0];
            }
        }

        return result;
    }
};