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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL, *current = head, *next;
        while(current){
            next = current->next;
            current-> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1), l2 = reverseList(l2);
        ListNode *res = new ListNode(0);
        ListNode *current = res;
        int carry = 0;
        while(l1 || l2 || carry){
            int a = (l1 != NULL) ? l1->val : 0;
            int b = (l2 != NULL) ? l2->val : 0;
            int sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            current->next = new ListNode(sum);
            current = current->next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        return reverseList(res->next);
    }
};