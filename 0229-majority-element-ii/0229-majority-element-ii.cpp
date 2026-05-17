class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand1=0;
        int cand2=1;
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                c1++;
            }
            else if(nums[i]==cand2){
                c2++;
            }
            else if(c1==0){
                cand1=nums[i];
                c1++;

            }
            else if(c2==0){
                cand2=nums[i];
                c2++;
            }
            else{
                c1--;c2--;
            }
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                ans1++;
            }
            if(nums[i]==cand2){
                ans2++;
            }

        }
        vector<int> arr;
        if(ans1>n/3){
            arr.push_back(cand1);
        }
        if(ans2>n/3){
            arr.push_back(cand2);
        }
        return arr;
    }
};