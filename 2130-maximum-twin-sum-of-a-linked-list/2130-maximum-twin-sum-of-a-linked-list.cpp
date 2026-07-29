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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* h1=NULL;
        while(fast && fast->next){
            h1=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* h2=slow;
        h1->next=NULL;
        ListNode* temp=head;
        ListNode* prev2=NULL;
        while(temp){
            ListNode* nd=temp->next;
            temp->next=prev2;
            prev2=temp;
            temp=nd;
        }
        int ans=0;
        while(h1){
            ans=max(ans,h1->val+h2->val);
            h1=h1->next;
            h2=h2->next;
        }
        return ans;


    }
};