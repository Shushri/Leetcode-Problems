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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pair<int,ListNode*>> pq;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            while(temp){
                pq.push({temp->val,temp});
                temp=temp->next;
            }
        }
        ListNode* head=nullptr;
        if(!pq.empty()){
            head=pq.top().second;
            head->next=nullptr;
            pq.pop();
        }
        ListNode* prev=head;
        while(!pq.empty()){
            ListNode* tp=pq.top().second;
            pq.pop();
            tp->next=prev;
            prev=tp;
            
        }
        return prev;

    }
};