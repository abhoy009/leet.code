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
        ListNode* dummyHead = new ListNode(); // Create a dummy head node
        ListNode* current = dummyHead; // Initialize a current node to build the result list
        
        int carry = 0; // Initialize the carry
        
        while (l1 || l2 || carry) {
            int sum = carry; // Initialize sum with the carry from the previous iteration
            
            // Add values from l1 and l2 if they exist
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // Update the carry
            
            current->next = new ListNode(sum % 10); // Create a new node with the current digit
            current = current->next; // Move the current pointer
            
        }
        
        return dummyHead->next; // Return the result list (skip the dummy head)
    }
};
