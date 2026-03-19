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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* temp=head;
            
            int c=0;
            while(temp){
                temp=temp->next;
                c++;
            }
            if(c==n){
                return head->next;
            }
            int cc=c-n+1;
            int p=1;
            temp=head->next;
            ListNode* prev=head;

            while(temp){
                p++;
                if(p==cc){
                    prev->next=temp->next;

                }
                else{
                    prev=temp;
                }
                temp=temp->next;
            }
            return head;
    }
};