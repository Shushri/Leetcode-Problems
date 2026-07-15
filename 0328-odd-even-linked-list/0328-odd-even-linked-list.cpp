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
         if(head==NULL || head->next==NULL) return head;
         ListNode* even=head->next;
         ListNode* tempo=head;
         ListNode* tempe=head->next;
         while(tempo && tempo->next){
            tempo->next=tempo->next->next;
            if(tempe->next){
                tempe->next=tempo->next->next;
                tempe=tempe->next;
            }
            if(tempo->next!=NULL) tempo=tempo->next;
            

         }
         tempo->next=even;
         return head;
    }
};