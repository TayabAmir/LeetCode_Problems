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
private:
    ListNode* dummy = new ListNode(0);
    ListNode* reverse_head = dummy;
public:
    void reverseLL(ListNode* head){
        if(head == NULL) return;
        reverseLL(head->next);
        reverse_head->next = new ListNode(head->val);
        reverse_head = reverse_head->next;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        reverseLL(head);
        return dummy->next;
    }
};