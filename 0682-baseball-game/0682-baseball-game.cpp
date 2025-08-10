class Solution {
public:
    int calPoints(vector<string>& op) {
        int n=op.size();
        vector <int> ans;
        for (int i=0;i<n;i++){
            
            if(op[i]=="+"){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }
            else if(op[i]=="D"){
                ans.push_back(2*ans[ans.size()-1]);
            }
            else if(op[i]=="C"){
                ans.erase(ans.begin()+ans.size()-1);
            }
            else{
                ans.push_back(stoi(op[i]));
            }
        }
        int sum=0;
        for (auto ele:ans){
            sum+=ele;
        }
        return sum;

    }
};