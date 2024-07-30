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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head, *ptr2 = head;
        int n = k-1;
        while(n--)
            ptr2 = ptr2 -> next;
        ListNode* begin = ptr2;
        while(ptr2->next)
            ptr1 = ptr1->next,ptr2 = ptr2->next;
        swap(ptr1->val,begin->val);
        return head;
    }
};