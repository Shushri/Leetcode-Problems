class Solution {
public:
    int strStr(string h, string n) {
        if(h.size()<n.size()){
            return -1;
        }
        size_t pos=h.find(n);
        if (pos != std::string::npos){
            return pos;

        }
        
        return -1;
    }
};