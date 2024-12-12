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
    ListNode* middle(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
    ListNode* mergeLists(ListNode* left, ListNode* right) {
        if (!left)
            return right;
        if (!right)
            return left;

        if (left->val <= right->val) {
            left->next = mergeLists(left->next, right);
            return left;
        } else {
            right->next = mergeLists(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = middle(head);
        ListNode* secondHalf = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);

        return mergeLists(left, right);
    }
};