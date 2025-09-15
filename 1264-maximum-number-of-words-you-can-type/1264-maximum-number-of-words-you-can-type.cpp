class Solution {
public:
    int canBeTypedWords(string text, string b) {
        istringstream iss(text);
        vector <string> arr;
        string word;
        int c=0;
        while(iss >> word ){
            arr.push_back(word);
        }
        for(int i=0;i<arr.size();i++){
            int f=0;
            for(int j=0;j<arr[i].size();j++){
                if(b.find(arr[i][j])!=std::string::npos){
                    f=1;
                    break;
                }
            }
            if(f==0){
                c++;
            }
        }
        return c;

    }
};