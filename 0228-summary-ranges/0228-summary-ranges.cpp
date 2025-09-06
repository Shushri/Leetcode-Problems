class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        else if(nums.size()==1){
            return {to_string(nums[0])};
        }
        vector<string> ans;

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if((long long)nums[i]-(long long)nums[i-1]==1){
                temp.push_back(nums[i]);
            }
            else{
                if(temp.size()==1){
                    string s=to_string(temp[0]);
                    ans.push_back(s);
                    temp={nums[i]};
                }
                else{
                    string s=to_string(temp[0]);
                    s+="->";
                    s+=to_string(temp[temp.size()-1]);
                    ans.push_back(s);
                    temp={nums[i]};
                }                
            }
        }
        if(temp.size()==1){
                    string s=to_string(temp[0]);
                    ans.push_back(s);
                   
                }
                else{
                    string s=to_string(temp[0]);
                    s+="->";
                    s+=to_string(temp[temp.size()-1]);
                    ans.push_back(s);
                   
                }
        return ans;
    }
};