class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* merged = nullptr; // The merged list
        ListNode* current = nullptr; // Pointer to the last node of the merged list

        if (list1->val < list2->val) {
            merged = list1;
            current = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            current = list2;
            list2 = list2->next;
        }

        while (list1 && list2) {
            if (list1->val < list2->val) {
                current->next = list1;
                current = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = list2;
                list2 = list2->next;
            }
        }

        if (list1)
            current->next = list1;
        else
            current->next = list2;

        return merged;
    }
};
