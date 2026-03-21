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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;
        ListNode* anshead=new ListNode(-1);
        ListNode* ans=anshead;
        int c=0;
        while(h1 && h2){
            int num=h1->val+h2->val+c;
            c=num/10;
            ListNode* pp=new ListNode(num%10);
            ans->next=pp;
            ans=ans->next;
            h1=h1->next;
            h2=h2->next;

        }
        while(h1){
            int num=h1->val+c;
            c=num/10;
            ListNode* pp=new ListNode(num%10);
            ans->next=pp;
            ans=ans->next;
            h1=h1->next;
            
        }
        while(h2){
            int num=h2->val+c;
            c=num/10;
            ListNode* pp=new ListNode(num%10);
            ans->next=pp;
            ans=ans->next;

            h2=h2->next;
        }
        if(c){
            ListNode* pp=new ListNode(1);
            ans->next=pp;
        }
        return anshead->next;
    }
};