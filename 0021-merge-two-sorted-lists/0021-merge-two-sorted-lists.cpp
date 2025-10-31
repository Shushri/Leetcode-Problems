class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* ans = &dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                ans->next = temp1;
                temp1 = temp1->next;
            } else {
                ans->next = temp2;
                temp2 = temp2->next;
            }
            ans = ans->next; // ✅ move ans forward
        }

        // Attach any remaining nodes
        if (temp1) ans->next = temp1;
        else ans->next = temp2;

        return dummy.next;
    }
};
