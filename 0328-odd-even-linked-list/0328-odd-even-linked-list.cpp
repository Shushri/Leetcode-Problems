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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenh=new ListNode(-1);
        ListNode* even=evenh;
        ListNode* oddh=new ListNode(-1);
        ListNode* odd=oddh;
        ListNode* temp=head;
        while(temp){
            odd->next=temp;
            if(odd->next)
                odd=odd->next;
            temp=temp->next;
            if(temp){
                even->next=temp;
                even=even->next;
                temp=temp->next;
            }

        } 
        even->next=NULL;
        odd->next=evenh->next;
        return oddh->next;

    }
};