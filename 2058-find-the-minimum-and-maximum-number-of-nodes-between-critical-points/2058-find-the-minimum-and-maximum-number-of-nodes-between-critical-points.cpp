/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* prev=head;
        int d=1;
        vector<int> arr;
        while(temp->next){
            if((temp->val>prev->val && temp->val>temp->next->val) || (temp->val<prev->val && temp->val<temp->next->val)){
                arr.push_back(d);
            }
            d++;
            prev=temp;
            temp=temp->next;
        }
        
        if(arr.size()<=1){
            return {-1,-1};
        }
        int mn=INT_MAX;
        
        for(int i=1;i<arr.size();i++){
            mn=min(mn,arr[i]-arr[i-1]);
            
        }
        int mx=arr[arr.size()-1]-arr[0];

        return {mn,mx};
    }
};
//1 4 