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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                current->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                current->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            current = current->next;
        }
        while(l1){
            current->next = new ListNode(l1->val);
            current = current->next;
            l1 = l1->next;
        }
        while(l2){
            current->next = new ListNode(l2->val);
            current = current->next;
            l2 = l2->next;
        }
        return dummy->next;
    }
};