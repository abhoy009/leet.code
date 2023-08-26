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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        // Count the number of nodes in the list
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If there are at least k nodes, reverse the current k-group
        if (count == k) {
            curr = reverseKGroup(curr, k); // Recurse for the remaining part
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            head = curr;
        }
        
        return head;
    }
};
